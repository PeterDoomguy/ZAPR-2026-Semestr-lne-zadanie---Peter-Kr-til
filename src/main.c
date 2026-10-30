#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help() {
    printf("Usage: program [options]\n");
    printf("Options:\n");
    printf("  -h, --help      Display this help message\n");
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}
enum command {
    CMD_UNKNOWN,
    CMD_CREW,
    CMD_DAYS,
    CMD_FOOD,
    CMD_OXYGEN,
    CMD_SOLAR_STORM,
    CMD_NON_INTERACTIVE,
    CND_START
};
void SimulationStarted(int c, int d, int f, int o);
void SpracovanieProgramu(enum command cmd,int hodnota);
int main(int argc, char *argv[]) {
    // spracovanie argumentov podľa návodu https://zapr.interes.group/guides/program_arguments/
    int help = 0;

    enum command cmd = CMD_UNKNOWN;

    const int MIN_CREW = 1;
    const int MAX_CREW = 100;

    const int MIN_DAYS = 1;
    const int MAX_DAYS = 365;

    const int MIN_FOOD = 0;
    const int MAX_FOOD = 1000000;

    const int MIN_OXYGEN = 0;
    const int MAX_OXYGEN = 1000000;

    int informationProcessed = 0;
    if (argc <= 1) {
        print_help();
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        // TODO pridaj ďalšie argumenty alebo to prerob podľa seba
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            help = 1;
            break;
        }
        if (strcmp(argv[i], "--crew") == 0 ) {
            if (i + 1 >= argc || (atoi(argv[i + 1]) > MAX_CREW ) || (atoi(argv[i + 1]) < MIN_CREW )){
                printf("Chyba: --crew chybna hodnota zadaj hodnoty %d az %d.\n", MIN_CREW, MAX_CREW);
                return 1;
            }
            SpracovanieProgramu(CMD_CREW, atoi(argv[i + 1]));
            i++;
        } else if (strcmp(argv[i], "--days") == 0) {
            if (i + 1 >= argc || (atoi(argv[i + 1]) > MAX_DAYS ) || (atoi(argv[i + 1]) < MIN_DAYS )){
                printf("Chyba: --days chybna hodnota zadaj hodnoty %d az %d.\n", MIN_DAYS, MAX_DAYS);
                return 1;
            }
            SpracovanieProgramu(CMD_DAYS, atoi(argv[i + 1]));
            i++;
        } else if (strcmp(argv[i], "--food") == 0){
            if (i + 1 >= argc || (atoi(argv[i + 1]) > MAX_FOOD ) || (atoi(argv[i + 1]) < MIN_FOOD )){
                printf("Chyba: --food chybna hodnota zadaj hodnoty %d az %d.\n", MIN_FOOD, MAX_FOOD);
                return 1;
            }
            SpracovanieProgramu(CMD_FOOD, atoi(argv[i + 1]));
            i++;

        } else if (strcmp(argv[i], "--oxygen") == 0) {
            if (i + 1 >= argc || (atoi(argv[i + 1]) > MAX_OXYGEN ) || (atoi(argv[i + 1]) < MIN_OXYGEN )) {
                printf("Chyba: --oxygen chybna hodnota zadaj hodnoty %d az %d.\n", MIN_OXYGEN, MAX_OXYGEN);
                return 1;
            }
            SpracovanieProgramu(CMD_OXYGEN, atoi(argv[i + 1]));
            i++;
        } else if (strcmp(argv[i], "--solar-storm") == 0) {
            SpracovanieProgramu(CMD_SOLAR_STORM,0);

        } else if (strcmp(argv[i], "--non-interactive") == 0) {
            SpracovanieProgramu(CMD_NON_INTERACTIVE,0);
        } else {
            printf("Unknown option: %s\n", argv[i]);
        }
    }
    informationProcessed = 1;

    if (informationProcessed) {SpracovanieProgramu(CND_START,0);}
    if (help) print_help();

    // TODO implementuj svoje riešenie

    return 0;
}

void SpracovanieProgramu(enum command cmd,int hodnota) {
    int crew, days, food, oxygen;
    switch (cmd) {
    case CMD_CREW:
        printf("Pocet posadky: %d\n", hodnota);
        crew = hodnota;
        break;

    case CMD_DAYS:
        printf("Pocet dni: %d\n", hodnota);
        days = hodnota;
        break;

    case CMD_FOOD:
        printf("Jedlo: %d\n", hodnota);
        food = hodnota;
        break;

    case CMD_OXYGEN:
        printf("Kyslik: %d\n", hodnota);
        oxygen = hodnota;
        break;

    case CMD_SOLAR_STORM:
        printf("Solarna burka!\n");
        break;
    case CND_START:
        printf("====== RIADIACE STREDISKO ======\n");
        SimulationStarted(crew,days,food,oxygen);
        printf("--------------------------------");

    default:
        printf("Neznamy prikaz\n");
        break;
    }
}
// Spotrebovane jedlo pre jednotlivca je len jedno.
// Spotrebovaný kyslík sú 2.
void SimulationStarted(int c, int d, int f, int o){
    int countDay = 0;
    int zostavajuceJedlo = 0;
    int zostavajuciKyslík = 0;
    while (countDay >= d){
        printf("%d/%d", countDay, d);
        f = f - c;
        o = o - (c * 2);
        zostavajuceJedlo = f;
        zostavajuciKyslík = o;

        printf("Spotrebované jedlo: %d", f);
        printf("Spotrebovaný kyslík: %d", o);
        printf("Zostávajúce jedlo: %d", zostavajuceJedlo);
        printf("Zostávajúci kyslík: %d", zostavajuciKyslík);

        countDay++;

        char c;
        putchar(c);

        printf("--------------------------------");
    }
}

