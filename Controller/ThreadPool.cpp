//
// Created by Emma on 11/12/2024.
//

#include "ThreadPool.h"
// Programme C++ pour démontrer l'utilisation d'un pool de threads

#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

// Constructeur du ThreadPool
ThreadPool::ThreadPool(size_t num_threads = thread::hardware_concurrency()) {
    // Création des threads travailleurs
    for (size_t i = 0; i < num_threads; ++i) {
        // Chaque thread exécute une fonction lambda qui reste active
        // tant que le pool de threads n'est pas arrêté
        threads_.emplace_back([this] {
            while (true) {
                function<void()> task;

                // Verrouillage pour accéder en toute sécurité à la file de tâches
                {
                    unique_lock<mutex> lock(queue_mutex_);

                    // Attente jusqu'à ce qu'une tâche soit disponible
                    // ou que le pool de threads soit arrêté
                    cv_.wait(lock, [this] {
                        // Condition : il y a des tâches ou le pool est arrêté
                        return !tasks_.empty() || stop_;
                    });

                    // Si le pool est arrêté et qu'il n'y a plus de tâches, on quitte le thread
                    if (stop_ && tasks_.empty()) {
                        return;
                    }

                    // Récupération de la tâche en tête de la file
                    task = move(tasks_.front());
                    tasks_.pop();
                }

                // Exécution de la tâche hors de la section critique
                // Cela permet à d'autres threads de récupérer des tâches
                task();
            }
        });
    }
}

// Destructeur du ThreadPool
ThreadPool::~ThreadPool() {
    {
        // Verrouillage pour définir en toute sécurité le drapeau d'arrêt
        unique_lock<mutex> lock(queue_mutex_);
        stop_ = true; // Indique aux threads qu'ils doivent arrêter
    }

    // Notifie tous les threads en attente dans la file de tâches
    cv_.notify_all();

    // Attente que tous les threads terminent leur exécution
    for (auto& thread : threads_) {
        thread.join(); // Bloque jusqu'à ce que le thread se termine
    }
}

// Méthode pour ajouter une tâche dans la file du pool de threads
void ThreadPool::enqueue(function<void()> task) {
    {
        // Verrouillage pour ajouter en toute sécurité une tâche à la file
        unique_lock<std::mutex> lock(queue_mutex_);
        tasks_.emplace(move(task)); // Ajoute la tâche à la file
    }

    // Notifie un thread en attente qu'une nouvelle tâche est disponible
    cv_.notify_one();
}
