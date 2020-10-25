#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *oath_parts[] = {
    "On my honor",
    "I will do my best",
    "to do my duty",
    "to God and my country,",
    "to help other people at all times,",
    "to obey the Scout Law,",
    "and to keep myself",
    "physically strong",
    "mentally awake",
    "and morally straight.",
    NULL
};

const char * findPhrase(const char *clue);
void doStudyLoop();

int main(int argc, char *argv[]) {
    if (argc==2 && 0==strcmp(argv[1],"-all")) {
        int i;
        for (i=0; oath_parts[i]; i++) {
            printf("%s ",oath_parts[i]);
            if (i%2==1) {
                printf("\n");
            }

        }
    } else if (argc==2) {
        const char * phrase;
        phrase = findPhrase(argv[1]);
        if (phrase) {
            printf("%s\n",phrase);
        } else {
            fprintf(stderr,"(not found)");
            return 1;
        }
    } else {
        doStudyLoop();
    }
    return 0;
}


const char * findPhrase(const char *clue) {
    int i;
    for (i=0; oath_parts[i]; i++) {
        if (strstr(oath_parts[i], clue)
            && oath_parts[i+1]) {
                return oath_parts[i+1];
        }
    }
    return NULL;
}

void chomp(char * s);

void doStudyLoop() {
    char line[81];
    const char *nextPhrase;
    while (NULL != fgets(line, 80, stdin)) {
        chomp(line);
        nextPhrase = findPhrase(line);
        if (nextPhrase) {
            printf(" -> %s\n",nextPhrase);
        } else {
            printf("Not found... try again...\n");
        }
    }
}

void chomp(char *s) {
    for (;*s;s++) {
        if (*s == '\n') {
            *s = 0;
        }
    }
}