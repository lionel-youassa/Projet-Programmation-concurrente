import os

# Dossiers où chercher les fichiers source et header
directories_to_scan = [
    "Controller",

    "Model/classDefinition",
    "Model/classDeclaration",
    "Model",

    "View",

]

# Extensions à rechercher
source_extensions = [".cpp"]
header_extensions = [".h"]

# Fonction pour collecter les fichiers
def collect_files(directories, extensions):
    files = []
    for directory in directories:
        if os.path.exists(directory):
            for root, _, filenames in os.walk(directory):
                for filename in filenames:
                    if any(filename.endswith(ext) for ext in extensions):
                        files.append(os.path.join(root, filename).replace("\\", "/"))
    return files

# Collecte des sources et headers
source_files = collect_files(directories_to_scan, source_extensions)
header_files = collect_files(directories_to_scan, header_extensions)

# Génération du contenu pour le fichier .pro
def generate_pro_content(target_name, source_files, header_files):
    pro_content = f"""# Déclare le type et le nom du projet
TEMPLATE = app
TARGET = {target_name}

# Fichiers source
SOURCES += \\
"""
    pro_content += " \\\n    ".join(source_files) + "\n\n"

    pro_content += """# Fichiers header
HEADERS += \\
"""
    pro_content += " \\\n    ".join(header_files) + "\n\n"

    pro_content += """# Ajout des fichiers ressources
RESOURCES += ressources.qrc

# Modules Qt nécessaires
QT += widgets gui

# Configuration spécifique
CONFIG += c++17

# Répertoires d'inclusion
INCLUDEPATH += \\
"""
    include_paths = set(os.path.dirname(f) for f in source_files + header_files)
    pro_content += " \\\n    ".join(sorted(include_paths)) + "\n"

    return pro_content

# Nom du projet
target_name = "masterchef_info"

# Générer le contenu
pro_file_content = generate_pro_content(target_name, source_files, header_files)

# Sauvegarder dans un fichier .pro
with open("masterchef_info.pro", "w", encoding="utf-8") as pro_file:
    pro_file.write(pro_file_content)

print("Fichier .pro généré avec succès !")
