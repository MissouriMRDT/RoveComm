# adam wrote this but sent it to me on discord instead of pushing it
# TODO: rewrite in ruby lol
import json

# source file
json_path = "manifest.json"
# destination file
file_path = "README.md"

def main():
    with open(json_path, "r") as file:
        manifest = json.load(file)
    
    with open(file_path, "w") as file:
        file.write("# RoveComm Manifest\n\n")

        for board_name, board_desc in manifest["RovecommManifest"].items():
            file.write(f"## {board_name} Board\n\n")
            file.write(f"IP: {board_desc['Ip']}\n\n")
            if "Commands" in board_desc:
                file.write("### Commands\n\n")
                file.write("| name | dataId | type | count | description |\n")
                file.write("| :--- | ------ | ---- | ----- | ----------- |\n")
                for packet_name, packet_desc in board_desc["Commands"].items():
                    file.write(f"| **{packet_name}** ")
                    file.write(f"| {packet_desc['dataId']} ")
                    file.write(f"| `{packet_desc['dataType']}` ")
                    file.write(f"| {packet_desc['dataCount']} ")
                    file.write(f"| {packet_desc['comments']} |\n")
                file.write("\n")
            if "Telemetry" in board_desc:
                file.write("### Telemetry\n\n")
                file.write("| name | dataId | type | count | description |\n")
                file.write("| :--- | ------ | ---- | ----- | ----------- |\n")
                for packet_name, packet_desc in board_desc["Telemetry"].items():
                    file.write(f"| **{packet_name}** ")
                    file.write(f"| {packet_desc['dataId']} ")
                    file.write(f"| `{packet_desc['dataType']}` ")
                    file.write(f"| {packet_desc['dataCount']} ")
                    file.write(f"| {packet_desc['comments']} |\n")
                file.write("\n")
            if "Error" in board_desc:
                file.write("### Errors\n\n")
                file.write("| name | dataId | type | count | description |\n")
                file.write("| :--- | ------ | ---- | ----- | ----------- |\n")
                for packet_name, packet_desc in board_desc["Error"].items():
                    file.write(f"| **{packet_name}** ")
                    file.write(f"| {packet_desc['dataId']} ")
                    file.write(f"| `{packet_desc['dataType']}` ")
                    file.write(f"| {packet_desc['dataCount']} ")
                    file.write(f"| {packet_desc['comments']} |\n")
                file.write("\n")

if __name__ == "__main__":
    main()