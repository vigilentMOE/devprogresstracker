#!/bin/bash

# Path to the .bashrc file
BASHRC_PATH="$HOME/.bashrc"

# Check if the .bashrc file exists
if [[ ! -f "$BASHRC_PATH" ]]; then
  echo "Error: .bashrc file not found in home directory."
  exit 1
fi

# Initialize flag for capturing alias lines
capture_aliases=false

# Read the .bashrc file line-by-line
while read -r line; do
  # Check for the "Aliases" start marker
  if [[ "$line" == "# Aliases" ]]; then
    capture_aliases=true
    continue
  fi

  # Check for the "End Aliases" stop marker
  if [[ "$line" == "# End Aliases" ]]; then
    capture_aliases=false
  fi

  # If in capture mode, print lines starting with 'alias'
  if [[ "$capture_aliases" == true && "$line" == alias* ]]; then
    echo "$line"
  fi
# 1. 'done' marks the end of the loop.
# 2. '< "$BASHRC_PATH"' redirects the file content of the .bashrc file into the loop.
# This way, 'read -r line' reads each line from .bashrc into the variable 'line' during each loop iteration.
done < "$BASHRC_PATH"