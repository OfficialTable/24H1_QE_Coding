'''Version 1'''

# import os
# import datetime

# log_file = 'file_count_log.txt'
# today = datetime.datetime.now()
# date_format = "%Y-%m-%d (%H%M%S)"
# search_directory = './'
# folders = [folder for folder in os.listdir(search_directory) if os.path.isdir(os.path.join(search_directory, folder)) and not folder.startswith('.') and not folder.startswith('git')]
# file_counts = {folder: 0 for folder in folders}

# if os.path.exists(log_file):
#     with open(log_file, 'r') as f:
#         lines = f.readlines()
#         if lines:
#             last_log = lines[-1].strip()
#             date_str, file_count_str = last_log.split(':', 1)

# for folder in folders:
#     folder_path = os.path.join(search_directory, folder)
#     file_counts[folder] = len(os.listdir(folder_path))

# with open(log_file, 'a') as f:
#     log_date = today.strftime(date_format)
#     log_str = f"{log_date}: {{"
#     log_str += ', '.join([f"{folder}: {count}" for folder, count in file_counts.items()])
#     log_str += "}\n"
#     f.write(log_str)

# print(f"{log_date}: {file_counts}")

'''version 2'''

import os
import datetime

log_file = 'file_count_log.txt'
today = datetime.datetime.now()
date_format = "%Y-%m-%d (%H%M%S)"
search_directory = './'

folders = [folder for folder in os.listdir(search_directory) if os.path.isdir(os.path.join(search_directory, folder)) and not folder.startswith('.') and not folder.startswith('git')]

file_counts = {folder: {'total': 0, '.py': 0, '.c': 0} for folder in folders}

if os.path.exists(log_file):
    with open(log_file, 'r') as f:
        lines = f.readlines()
        if lines:
            last_log = lines[-1].strip()
            date_str, file_count_str = last_log.split(':', 1)

for folder in folders:
    folder_path = os.path.join(search_directory, folder)
    files = os.listdir(folder_path)
    
    for file in files:
        if file.endswith('.py'):
            file_counts[folder]['.py'] += 1
        elif file.endswith('.c'):
            file_counts[folder]['.c'] += 1
    
    file_counts[folder]['total'] = len(files)

with open(log_file, 'a') as f:
    log_date = today.strftime(date_format)
    log_str = f"{log_date}: {{"
    for folder, counts in file_counts.items():
        log_str += f"{folder}: total={counts['total']}, .py={counts['.py']}, .c={counts['.c']}, "
    log_str = log_str.rstrip(', ')
    log_str += "}\n"
    f.write(log_str)

print(f"{log_date}: {file_counts}")

