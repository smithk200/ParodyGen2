import os
import re

# Root folder to scan
root_dir = 'C:\decomps\DJ\data\maps'

## Regex to find lines with .string
string_line_re = re.compile(r'\.string', re.IGNORECASE)

# Regex to match words outside of brackets
word_re = re.compile(r'\b\w+\b')

# Regex to match placeholders
placeholder_re = re.compile(r'\{.*?\}')

def convert_if_all_caps(word):
    if word.isupper():
        return word.capitalize()
    return word

def process_line(line):
    # This function will replace all-caps words outside of {placeholders}
    result = []
    last_index = 0

    for match in placeholder_re.finditer(line):
        # Process text before the placeholder
        pre_text = line[last_index:match.start()]
        pre_text = word_re.sub(lambda m: convert_if_all_caps(m.group(0)), pre_text)
        result.append(pre_text)

        # Append placeholder as-is
        result.append(match.group(0))
        last_index = match.end()

    # Process any text after the last placeholder
    post_text = line[last_index:]
    post_text = word_re.sub(lambda m: convert_if_all_caps(m.group(0)), post_text)
    result.append(post_text)

    return ''.join(result)

for dirpath, dirnames, filenames in os.walk(root_dir):
    for filename in filenames:
        if filename == "scripts.inc":
            file_path = os.path.join(dirpath, filename)
            print("Processing:", file_path)

            with open(file_path, 'r') as f:
                lines = f.readlines()

            new_lines = []
            for line in lines:
                if string_line_re.search(line):
                    line = process_line(line)
                new_lines.append(line)

            # Overwrite the file with modified content
            with open(file_path, 'w') as f:
                f.writelines(new_lines)

print("Done processing all scripts.inc files.")
