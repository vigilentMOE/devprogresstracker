#!/bin/bash

# Check if any arguments are passed
if [[ $# -eq 0 ]]; then
    echo "This script quicky uploads to git"
    echo "Usage:"
    echo "First arguement is commit message"
    echo "Second arguement is remote branch destination"
    exit 0
fi

# Check for the required argument
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <commit message> <branch name>"
  exit 1
fi

# Assign arguments to variables
commit_message="$1"
branch_name="$2"

# Execute Git commands
git add *
git commit -m "$commit_message"
git push -u origin "$branch_name"
