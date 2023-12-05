search_string_decode() {
  # Check if there are any arguments provided
  if [ $# -eq 0 ]; then
    echo "Usage: search_string_decode <directory>"
    return 1
  fi

  # Get the directory path from the argument
  directory=$1

  # Check if the directory exists
  if [ ! -d "$directory" ]; then
    echo "Directory not found: $directory"
    return 1
  fi

  # Use grep to search for the word "string_decode" in all files in the specified directory
  grep -r -n --color=auto "string_decode" "$directory"
}