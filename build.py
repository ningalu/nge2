import sys
import os
from subprocess import Popen
import json

def print_help(platform):
    configs = [c for c in platform["commands"]]
    for c in configs:
        print(f"{c['name']}: {c['description']}")

with open("buildconfig.json", "r") as settings_file:
    settings = json.load(settings_file)
    [platform] = [p for p in settings["platforms"] if p["name"] == sys.platform]
    if (len(sys.argv) > 1):
        if (sys.argv[1] == "help"):
            print_help(platform)
        else:
            [config] = [c for c in platform["commands"] if c["name"] == sys.argv[1]]
            s = platform["path_separator"]
            for script in config["scripts"]:
                script_absolute_path = f"{os.path.dirname(os.path.realpath(__file__))}{s}buildscripts{s}{script}"
                print("Running " + script_absolute_path)
                Popen(script_absolute_path).wait()
    else:
        print_help(platform)