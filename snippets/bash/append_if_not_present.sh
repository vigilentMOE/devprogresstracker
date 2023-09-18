# Function to append value to a variable only if it's not already present
append_if_not_present() {
  variable_name="$1"
  value_to_append="$2"
  eval current_value=\$$variable_name

  if [[ ! ":$current_value:" == *":$value_to_append:"* ]]; then
    export "$variable_name"="$current_value:$value_to_append"
  fi
}

# Update PATH
append_if_not_present "PATH" "/home/vigmoe/bin"

# Update C_INCLUDE_PATH
append_if_not_present "C_INCLUDE_PATH" "/home/vigmoe/dev/cs50_repo/libcs50/src"
