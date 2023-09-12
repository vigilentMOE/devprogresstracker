#!/bin/bash

# Check if any arguments are passed
if [[ $# -eq 0 ]]; then
    echo "This script recursively downloads a website and extracts all human-readable strings from it."
    echo "Usage:"
    echo "  $0 <output_folder> <website_url>  # Downloads website content and extracts strings"
    echo "  $0                             # Prints this help message"
    exit 0
fi

# Check if enough arguments are passed
if [[ $# -ne 2 ]]; then
    echo "Usage: $0 <output_folder> <website_url>"
    exit 1
fi

# Assign arguments to variables
output_folder=$1
website_url=$2

# Create the output folder if it doesn't exist
mkdir -p "$output_folder"

# Download the website content recursively
wget --recursive --no-parent "$website_url" -P "$output_folder"

# Navigate to the downloaded folder
# The basename command in Bash is used to strip directory and suffix information from filenames. Essentially, it outputs the filename itself, devoid of parent directories, and optionally removes the file extension.
cd "$output_folder/$(basename $website_url)"


# - `find`: The command utility for file search.
# - `.`: Specifies the starting directory for the search, in this case, the current directory.
# - `-type f`: Restricts the search to regular files, excluding directories, symbolic links, etc.
# - `-exec strings {} \;`: For each file found, executes the `strings` command.
#   - `strings`: A utility that prints the sequences of printable characters in a file.
#   - `{}`: A placeholder that `find` replaces with the current file name being processed.
#   - `\;`: Terminates the `-exec` command; the backslash escapes the semicolon so that it gets passed to `find` instead of being interpreted by the shell.
# - `> all_strings.txt`: Redirects the standard output to a file named `all_strings.txt`, overwriting the file if it exists or creating it if it doesn't.

# ### Operation Sequence

# 1. `find` starts at the current directory (`.`) and traverses the directory tree.
# 2. For each regular file (`-type f`), it executes (`-exec`) the `strings` command.
# 3. `strings` reads the file and outputs printable character sequences to the standard output.
# 4. The standard output is then redirected (`>`) to `all_strings.txt`, either overwriting the existing file or creating a new one.

# In summary, this command searches for all regular files starting from the current directory, extracts printable strings from each of them using the `strings` utility, and saves all these strings into a single file named `all_strings.txt`.
find . -type f -exec strings {} \; > all_strings.txt

# Optional: Clean up the output
# Uncomment the line below to remove unwanted patterns
# grep -v "unwanted_pattern" all_strings.txt > cleaned_strings.txt

echo "All human-readable strings have been saved in $output_folder/$(basename $website_url)/all_strings.txt"
