// game.h
#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20
#define MAX_INVENTORY_SIZE 10
#define MAX_QUEST_SIZE 5
#define MAX_MAP_SIZE 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char weakness[MAX_NAME_LENGTH];
    int base_dmg;
    int base_hp;
} Race;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char weakness[MAX_NAME_LENGTH];
    int dmg;
    int hp;
    int xp;
} Enemy;

typedef struct {
    char symbol[2];
    char name[MAX_NAME_LENGTH];
    int bns_hp;
    int bns_dmg;
} Totem;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int effect;
} Item;

typedef struct {
    char description[100];
    int completed;
} Quest;

typedef struct {
    Race race;
    Totem totem;
    int total_hp;
    int total_dmg;
    int contract;
    int level;
    int sub_level;
    int hp_bottles;
    float coins;
    Item* inventory;
    int inventory_size;
    Quest quests[MAX_QUEST_SIZE];
    int quest_count;
    int x;
    int y;
} Player;

typedef struct {
    char description[100];
    int enemy_present;
    int item_present;
} MapTile;

// Function prototypes
void init_game(Player* player, MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE]);
void save_game(Player* player);
void load_game(Player* player);
void print_ascii_art(const char* art_name);
void battle(Player* player, Enemy* enemy);
void merchant(Player* player);
void add_item_to_inventory(Player* player, Item item);
void remove_item_from_inventory(Player* player, int index);
void print_inventory(Player* player);
void level_up(Player* player);
void move_player(Player* player, MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE], char direction);
void print_map(MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE], Player* player);
void add_quest(Player* player, const char* description);
void check_quests(Player* player);
void parse_command(Player* player, MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE], char* command);

#endif

// game.c
#include "game.h"

void init_game(Player* player, MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
    // Initialize player
    player->level = 1;
    player->sub_level = 0;
    player->hp_bottles = 3;
    player->coins = 0;
    player->inventory = malloc(sizeof(Item) * MAX_INVENTORY_SIZE);
    player->inventory_size = 0;
    player->quest_count = 0;
    player->x = 0;
    player->y = 0;

    // Initialize map
    for (int i = 0; i < MAX_MAP_SIZE; i++) {
        for (int j = 0; j < MAX_MAP_SIZE; j++) {
            sprintf(map[i][j].description, "An empty area");
            map[i][j].enemy_present = 0;
            map[i][j].item_present = 0;
        }
    }

    // Add some random enemies and items to the map
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int x = rand() % MAX_MAP_SIZE;
        int y = rand() % MAX_MAP_SIZE;
        map[x][y].enemy_present = 1;
        sprintf(map[x][y].description, "A dangerous area");
    }
    for (int i = 0; i < 3; i++) {
        int x = rand() % MAX_MAP_SIZE;
        int y = rand() % MAX_MAP_SIZE;
        map[x][y].item_present = 1;
        sprintf(map[x][y].description, "An area with a hidden item");
    }
}

void save_game(Player* player) {
    FILE* file = fopen("save.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    fwrite(player, sizeof(Player), 1, file);
    fwrite(player->inventory, sizeof(Item), player->inventory_size, file);
    fclose(file);
    printf("Game saved successfully.\n");
}

void load_game(Player* player) {
    FILE* file = fopen("save.dat", "rb");
    if (file == NULL) {
        printf("No save file found.\n");
        return;
    }
    fread(player, sizeof(Player), 1, file);
    player->inventory = malloc(sizeof(Item) * MAX_INVENTORY_SIZE);
    fread(player->inventory, sizeof(Item), player->inventory_size, file);
    fclose(file);
    printf("Game loaded successfully.\n");
}

void print_ascii_art(const char* art_name) {
    FILE* file = fopen(art_name, "r");
    if (file == NULL) {
        printf("Error opening ASCII art file.\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void battle(Player* player, Enemy* enemy) {
    printf("A battle has started with %s!\n", enemy->name);
    while (player->total_hp > 0 && enemy->hp > 0) {
        printf("Your HP: %d, Enemy HP: %d\n", player->total_hp, enemy->hp);
        printf("1. Attack\n2. Use Item\n3. Run\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enemy->hp -= player->total_dmg;
                printf("You dealt %d damage!\n", player->total_dmg);
                break;
            case 2:
                print_inventory(player);
                // Implement item use logic here
                break;
            case 3:
                if (rand() % 2 == 0) {
                    printf("You successfully ran away!\n");
                    return;
                } else {
                    printf("You failed to run away!\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        if (enemy->hp <= 0) {
            printf("You defeated the %s!\n", enemy->name);
            player->coins += rand() % 20 + 1;
            player->sub_level += enemy->xp;
            level_up(player);
            return;
        }

        player->total_hp -= enemy->dmg;
        printf("%s dealt %d damage to you!\n", enemy->name, enemy->dmg);

        if (player->total_hp <= 0) {
            printf("You were defeated...\n");
            exit(0);
        }
    }
}

void merchant(Player* player) {
    printf("Welcome to the merchant!\n");
    printf("1. Buy Health Potion (10 coins)\n");
    printf("2. Buy Strength Potion (20 coins)\n");
    printf("3. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (player->coins >= 10) {
                player->coins -= 10;
                Item health_potion = {"Health Potion", 50};
                add_item_to_inventory(player, health_potion);
                printf("You bought a Health Potion!\n");
            } else {
                printf("Not enough coins.\n");
            }
            break;
        case 2:
            if (player->coins >= 20) {
                player->coins -= 20;
                Item strength_potion = {"Strength Potion", 5};
                add_item_to_inventory(player, strength_potion);
                printf("You bought a Strength Potion!\n");
            } else {
                printf("Not enough coins.\n");
            }
            break;
        case 3:
            return;
        default:
            printf("Invalid choice.\n");
    }
}

void add_item_to_inventory(Player* player, Item item) {
    if (player->inventory_size < MAX_INVENTORY_SIZE) {
        player->inventory[player->inventory_size++] = item;
    } else {
        printf("Inventory is full!\n");
    }
}

void remove_item_from_inventory(Player* player, int index) {
    if (index >= 0 && index < player->inventory_size) {
        for (int i = index; i < player->inventory_size - 1; i++) {
            player->inventory[i] = player->inventory[i + 1];
        }
        player->inventory_size--;
    } else {
        printf("Invalid inventory index.\n");
    }
}

void print_inventory(Player* player) {
    printf("Inventory:\n");
    for (int i = 0; i < player->inventory_size; i++) {
        printf("%d. %s\n", i + 1, player->inventory[i].name);
    }
}

void level_up(Player* player) {
    if (player->sub_level >= 100) {
        player->level++;
        player->sub_level -= 100;
        player->total_hp += 10;
        player->total_dmg += 5;
        printf("You leveled up! You are now level %d\n", player->level);
    }
}

void move_player(Player* player, MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE], char direction) {
    int new_x = player->x;
    int new_y = player->y;

    switch(tolower(direction)) {
        case 'n': new_y--; break;
        case 's': new_y++; break;
        case 'e': new_x++; break;
        case 'w': new_x--; break;
        default: printf("Invalid direction.\n"); return;
    }

    if (new_x >= 0 && new_x < MAX_MAP_SIZE && new_y >= 0 && new_y < MAX_MAP_SIZE) {
        player->x = new_x;
        player->y = new_y;
        printf("You moved to a new area. %s\n", map[new_x][new_y].description);
        if (map[new_x][new_y].enemy_present) {
            Enemy enemy = {"Goblin", "None", 10, 50, 20};
            battle(player, &enemy);
        }
        if (map[new_x][new_y].item_present) {
            Item found_item = {"Mystery Item", 1};
            add_item_to_inventory(player, found_item);
            printf("You found a Mystery Item!\n");
            map[new_x][new_y].item_present = 0;
        }
    } else {
        printf("You can't move in that direction.\n");
    }
}

void print_map(MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE], Player* player) {
    for (int y = 0; y < MAX_MAP_SIZE; y++) {
        for (int x = 0; x < MAX_MAP_SIZE; x++) {
            if (x == player->x && y == player->y) {
                printf("P ");
            } else if (map[x][y].enemy_present) {
                printf("E ");
            } else if (map[x][y].item_present) {
                printf("I ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void add_quest(Player* player, const char* description) {
    if (player->quest_count < MAX_QUEST_SIZE) {
        Quest new_quest = {0};
        strncpy(new_quest.description, description, sizeof(new_quest.description) - 1);
        new_quest.completed = 0;
        player->quests[player->quest_count++] = new_quest;
        printf("New quest added: %s\n", description);
    } else {
        printf("Quest log is full!\n");
    }
}

void check_quests(Player* player) {
    printf("Current Quests:\n");
    for (int i = 0; i < player->quest_count; i++) {
        printf("%d. %s - %s\n", i + 1, player->quests[i].description,
               player->quests[i].completed ? "Completed" : "In Progress");
    }
}

void parse_command(Player* player, MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE], char* command) {
    char* token = strtok(command, " ");
    if (token == NULL) return;

    if (strcmp(token, "move") == 0) {
        token = strtok(NULL, " ");
        if (token != NULL && strlen(token) == 1) {
            move_player(player, map, token[0]);
        } else {
            printf("Invalid move command. Use 'move n/s/e/w'.\n");
        }
    } else if (strcmp(token, "inventory") == 0) {
        print_inventory(player);
    } else if (strcmp(token, "map") == 0) {
        print_map(map, player);
    } else if (strcmp(token, "quests") == 0) {
        check_quests(player);
    } else if (strcmp(token, "save") == 0) {
        save_game(player);
    } else if (strcmp(token, "load") == 0) {
        load_game(player);
    } else if (strcmp(token, "quit") == 0) {
        printf("Thanks for playing!\n");
        exit(0);
    } else {
        printf("Unknown command. Available commands: move, inventory, map, quests, save, load, quit\n");
    }
}

// main.c
#include "game.h"

int main(int argc, char* argv[]) {
    Player player;
    MapTile map[MAX_MAP_SIZE][MAX_MAP_SIZE];

    init_game(&player, map);

    if (argc > 1) {
        if (strcmp(argv[1], "-load") == 0) {
            load_game(&player);
        } else {
            printf("Unknown command line argument. Starting new game.\n");
        }
    }

    print_ascii_art("title.txt");
    printf("Welcome to the Adventure Game!\n");

    add_quest(&player, "Defeat 5 enemies");

    char command[100];
    while (1) {
        printf("\nEnter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline
        parse_command(&player, map, command);
    }

    free(player.inventory);
    return 0;
}
