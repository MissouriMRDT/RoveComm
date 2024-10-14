import json
import os
import argparse

def write_packet_section(file, section_name, packets):
    """
    Write a formatted table section for a specific packet type (e.g., Commands, Telemetry, Errors).
    
    This function generates a Markdown table and writes it to the specified file. It includes packet names, 
    data IDs, data types, data counts, and descriptions.

    Args:
        file (file object): The file object where the table is written.
        section_name (str): The title of the section (e.g., 'Commands', 'Telemetry', 'Errors').
        packets (dict): A dictionary containing packet information where the key is the packet name 
                        and the value is a dictionary with metadata such as dataId, dataType, dataCount, and comments.
    """
    if not packets:
        return  # Do not write anything if there are no packets

    file.write(f"### {section_name}\n\n")
    file.write("| name | dataId | type | count | description |\n")
    file.write("| :--- | ------ | ---- | ----- | ----------- |\n")

    # Iterate over each packet and write its details in Markdown table format
    for packet_name, packet_desc in packets.items():
        file.write(f"| **{packet_name}** ")
        file.write(f"| {packet_desc.get('dataId', 'N/A')} ")
        file.write(f"| `{packet_desc.get('dataType', 'N/A')}` ")
        file.write(f"| {packet_desc.get('dataCount', 'N/A')} ")
        file.write(f"| {packet_desc.get('comments', '')} |\n")

    file.write("\n")


def main(json_path, file_path):
    """
    Main function that reads a JSON manifest file and writes its content into a Markdown file.

    The function opens a JSON file (manifest.json) containing board and packet details, then 
    writes these details in a human-readable Markdown format to a README.md file. The resulting 
    file contains information for each board in sections, with subsections for Commands, Telemetry, 
    and Errors where applicable.

    Args:
        json_path (str): The path to the JSON manifest file.
        file_path (str): The path to the Markdown file to be generated.
    """
    # Check if the JSON file exists
    if not os.path.exists(json_path):
        print(f"Error: The file '{json_path}' does not exist.")
        return

    try:
        # Load the JSON manifest data
        with open(json_path, "r") as file:
            manifest = json.load(file)
    except json.JSONDecodeError as e:
        print(f"Error: Failed to parse JSON file. {e}")
        return

    try:
        # Open the README.md file for writing
        with open(file_path, "w") as file:
            file.write("# RoveComm Manifest\n\n")

            # Iterate over each board in the RoveComm manifest
            for board_name, board_desc in manifest.get("RovecommManifest", {}).items():
                file.write(f"## {board_name} Board\n\n")
                file.write(f"**IP**: {board_desc.get('Ip', 'N/A')}\n\n")

                # Write the 'Commands' section, if it exists
                if "Commands" in board_desc:
                    write_packet_section(file, "Commands", board_desc["Commands"])

                # Write the 'Telemetry' section, if it exists
                if "Telemetry" in board_desc:
                    write_packet_section(file, "Telemetry", board_desc["Telemetry"])

                # Write the 'Error' section, if it exists
                if "Error" in board_desc:
                    write_packet_section(file, "Errors", board_desc["Error"])

    except IOError as e:
        print(f"Error: Could not write to file '{file_path}'. {e}")


if __name__ == "__main__":
    # Setup argument parsing
    parser = argparse.ArgumentParser(description="Generate a README.md file from a JSON manifest.")
    parser.add_argument(
        "--json", 
        type=str, 
        default="manifest.json", 
        help="Path to the JSON manifest file (default: 'manifest.json')"
    )
    parser.add_argument(
        "--output", 
        type=str, 
        default="README.md", 
        help="Path to the output README file (default: 'README.md')"
    )

    # Parse arguments from command line
    args = parser.parse_args()

    # Run the main function with the provided or default arguments
    main(args.json, args.output)
