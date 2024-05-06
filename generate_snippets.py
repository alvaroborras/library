import os
import json
import sys

snippets = {}

directories = ['string']

for directory in directories:
    for filename in os.listdir(directory):
        name, extension = filename.split('.')
        if extension != 'cpp':
            continue

        if name in snippets:
            print(f'error: duplicate snippet {name}', file=sys.stderr)
            exit(0)

        path = os.path.join(directory, filename)
        with open(path, 'r') as f:
            snippet = {
                "prefix": name,
                "body": [line.rstrip() for line in f.readlines()],
                "description": name
            }
            snippets[name] = snippet

        print(f'generated snippet {name}', file=sys.stderr)

with open('cpp.json', 'w') as f:
    f.write(json.dumps(snippets, indent=2))

print('done', file=sys.stderr)
