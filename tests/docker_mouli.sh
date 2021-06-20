#!/usr/bin/bash
docker pull epitechcontent/epitest-docker
docker run --cap-add=SYS_PTRACE -it --rm -v $(pwd):/home/project -w /home/project epitechcontent/epitest-docker /bin/bash