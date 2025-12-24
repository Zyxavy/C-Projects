#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>


struct Item {
    char name[50];
    char description[200];
    int value;
};

struct Race
{
     char name[15];
     char weakness[15];
     int base_dmg;
     int base_hp;

 };

 struct Enemy
 {
    char name[15];
    char weakness[15];
    int dmg;
    int hp;
    int xp;
 };

 struct Totem
 {
     char symbol[2];
     char name[5];
     int bns_hp;
     int bns_dmg;
 };

 #define MAX_INVENTORY 10

 struct Player
{
    struct Race race;
    struct Totem totem;
    int total_hp;
    int total_dmg;
    int contract;
    int level;
    int sub_level;
    int hp_bottles;
    float coins;
    struct Item inventory[MAX_INVENTORY];
    int inventory_count;
};


 void Race_details(struct Race race)
 {
    printf("\n \t\t\t You are a %s.\n", race.name);
    printf("\t\t\tYour weakness is a %s.", race.weakness);
    printf("\n \t\t\tA base damage of %d. \n", race.base_dmg);
    printf("\t\t\tAnd you have a base hp of %d.\n", race.base_hp);
 }
 void Enemy_details(struct Enemy enemy)
 {
    printf("\n \t\t\tYour enemy is a %s\n", enemy.name);
    printf("\t\t\t%s is vulnerable to %s\n", enemy.name, enemy.weakness);
    printf("\t\t\t%s has %d damage.\n",  enemy.name, enemy.dmg);
    printf("\t\t\tAnd a base hp of %d.\n", enemy.hp);
}

void Totem_details(struct Totem totem)
{
    printf("\n \t\t\tA totem of %s %s.", totem.name, totem.symbol);
    printf("\n \t\t\tProvides: %d hp.", totem.bns_hp);
    printf("\n \t\t\tProvides: %d damage.", totem.bns_dmg);
}

struct Race select_race()
{
    struct Race races[] = {
        {"Gnome", "Goblin", 10, 59},
        {"Knight", "Lycantrope", 15, 45},
        {"Wizard", "Witch", 25, 34}
    };

    char input[20];
    while (1)
    {
        printf("\t\t\t\tSelect your race (Gnome, Knight, Wizard): ");
        scanf("%s", input);

        for (int i = 0; i < 3; i++)
        {
            if (strcmp(input, races[i].name) == 0)
            {
                return races[i];
            }
        }
        printf("\t\t\t\t\tInvalid race. Please try again.\n");
    }
}

struct Totem select_totem(struct Race race)
{
    struct Totem totems[] = {
        {"&", "Sloth",  15,  -5},
        {"$", "Greed",  6, 4},
        {"!", "Wrath",  -15, 10},
        {"0", "None", 0, 0}
        };

    char input[10];
    while(1)
    {
        printf("\n \t\t\tSelect your Totem(&, $, !, 0)\n");
        printf("\t\t\t");
        scanf(" %c", &input);

        for(int i = 0; i < 4; i++)
        {
            if(strcmp(input, totems[i].symbol) == 0)
                {
                    return totems[i];
                }
        }
        printf("\t\t\t\t\tInvalid Totem symbol, Try again.\n");
    }
}

struct Item generate_random_item() {
    struct Item items[] = {
        {"|Strength Elixir|", "|Increases damage by 5 for the next battle|", 50},
        {"|Lucky Charm|", "|Increases chance of item drops|", 75},
        {"|Rusty Sword|", "|An old sword, might be worth something|", 25},
        {"|Mysterious Amulet|", "|It glows faintly|", 100}
    };
    int num_items = sizeof(items) / sizeof(items[0]);
    return items[rand() % num_items];
}

struct Enemy create_goblin()
{
    struct Enemy goblin = {"Goblin", "Knight", 8, 30, 30};
    return goblin;
}

struct Enemy create_lycantrope()
{
    struct Enemy lycantrope = {"Lycantrope", "Wizard", 10, 35, 40};
    return lycantrope;
}

struct Enemy create_witch()
{
    struct Enemy witch = {"Witch", "Gnome", 15, 28, 45};
    return witch;
}

void battle(struct Player *player, struct Enemy *enemy);
void lvlup(struct Player *player);
void inventory(struct Player *player);
void merchant(struct Player *player);
void add_item_to_inventory(struct Player *player, struct Item item);
void remove_item_from_inventory(struct Player *player, int index);
void display_item_details(struct Item item);
void sell_items(struct Player *player);
void buy_items(struct Player *player);

int main()
{

     struct Player player;
     struct Enemy enemy;
     char proceed = 'n';
     player.hp_bottles = 3;

    printf("\t\t\t\t\t\tWELCOME!!\n");
    printf("\t\t\t\t\tWarning: Case Sensitive!!\n");
    sleep(1);

    do
    {
        player.race = select_race();
        Race_details(player.race);
        sleep(1);

        player.totem = select_totem(player.race);
        Totem_details(player.totem);

        player.total_hp = player.race.base_hp + player.totem.bns_hp;
        player.total_dmg = player.race.base_dmg + player.totem.bns_dmg;

        printf("\n \t\t\tYour total HP: %d\n", player.total_hp);
        printf("\t\t\t Your total damage: %d\n", player.total_dmg);
        sleep(1);
        printf("\n \t\t\tContinue? y/n: ");
        scanf(" %c", &proceed);
    } while(proceed == 'n'|| proceed == 'N');

    int scene1;
    char cont = 'n'; 
    do{
    printf("\n \t\t\tYou are lost in a forest, Which way do you go?\n");
    printf("\t\t\t\t1.Right | 2.Left | 3.Inventory:");
    scanf("%d", &scene1);

    if(scene1 == 1) {
        printf("\n \t\t\tYou went right.\n");
        sleep(1);
        struct Enemy goblin = create_goblin();
        battle(&player, &goblin);
        printf("\t\t\t \n\tContinue? y/n: ");
        scanf(" %c", &cont);
    } else if (scene1 == 2){
        printf("\n \t\t\tYou see a horde of Goblin, and a village, where do you go?\n");
        printf("\t\t\t \t1. Horde | 2. Village | 3.Inventory ");

        int scene2;
        scanf("%d", &scene2);
        do{
            if(scene2 == 1)
            {
                struct Enemy goblin = create_goblin();
                struct Enemy goblin2 = create_goblin();
                struct Enemy goblin3 = create_goblin();
                struct Enemy goblin4 = create_goblin();
                battle(&player, &goblin);
                sleep(1);
                battle(&player, &goblin2);
                sleep(1);
                battle(&player, &goblin3);
                sleep(1);
                battle(&player, &goblin4);
                printf("\n \t\t\t\tContinue? y/n: ");
                scanf(" %c", &cont);

            } else if(scene2 == 2){
                printf("\n \t\t\tYou went to the village.\n");
                cont = 'y';
            } else if(scene2 == 3){
                inventory(&player);
            }
        } while (cont != 'y');

    } else if(scene1 == 3){

        inventory(&player);
    } else{
        printf("\t\t\t Invalid Input\n");
    }
    } while(cont == 'n');
    sleep(1);
    cont = 'n';
    do{
        printf("\n \t\t\tYou arrived at a village and saw that it is in ruins.\n");
        sleep(1);
        printf("\t\t\t \t1. Explore | 2. leave the village | 3. Inventory:  ");
        int scene3;
        scanf("%d", &scene3);

        if(scene3 == 1){
            printf("\t\t\t You wandered around and encountered a lycantrope\n");
            sleep(1);
            struct Enemy lycantrope = create_lycantrope();
            battle(&player, &lycantrope);
             printf("\n \t\t\t\tContinue? y/n: ");
            scanf(" %c", &cont);


        } else if(scene3 == 2){
            printf("\t\t\t You fled from the village\n");
            sleep(1);
            printf("\t\t\t You were ambushed by a horde of lycantrope\n");
            struct Enemy lycantrope = create_lycantrope();
            battle(&player, &lycantrope);
            struct Enemy lycantrope2 = create_lycantrope();
            battle(&player, &lycantrope2);
            struct Enemy lycantrope3 = create_lycantrope();
            battle(&player, &lycantrope3);
            struct Enemy lycantrope4 = create_lycantrope();
            battle(&player, &lycantrope4);
             printf("\t\t\t\t \n\tContinue? y/n: ");
            scanf(" %c", &cont);

        } else if(scene3 == 3){
            inventory(&player);
        }
        else{
            printf("\t\t\t\t Invalid\n");
        }
    }while(cont == 'n');

    sleep(1);
    cont = 'n';
    do{
        sleep(1);
        printf("\n \t\t\t You managed to get away from the village.\n");
        printf("\t\t\t You see a shrine in the distance\n");
        printf("\t\t\t\t1. Pray in the shrine | 2. destroy the shrine| 3. Inventory: ");
        int scene4;
        scanf("%d", &scene4);

        if(scene4 == 1){
            printf("\t\t\tYou prayed in the shrine and recovered 70 hp and gained +5 dmg \n");
            player.total_hp += 70;
            player.total_dmg += 5;
            sleep(1);
            printf("\n \t\t\tContinue? y/n: ");
            scanf(" %c", &cont);
        } else if(scene4 == 2){
                printf("\t\t\tYou are cursed by the Gods, -6 damage\n");
                player.total_dmg -= 6;
                sleep(2);
                printf("\n \t\t\tThe Demon God has taken a liking to you\n");
                printf("\t\t\tThe Demon God offers a contract.\n");
                sleep(1);
                printf("\t\t\t\t1. Accept | 2. Reject\n");
                int contract;
                scanf("%d", &contract);

                    if(contract == 1){
                        printf("\t\t\tYou agreed to the conditions of the contract.\n");
                        sleep(1);
                        printf("\t\t\tYou can now level up, but enemies are now stronger and more hostile");
                        enemy.dmg += 3;
                        enemy.hp += 6;
                        player.contract = 1;
                        printf("\n \t\t\t\tContinue? y/n: ");
                        scanf(" %c", &cont);
                    } else if(contract == 2){
                        printf("\t\t\tYou rejected the Offer\n");
                        sleep(1);
                        printf("\t\t\tThe Demon God wishes you luck\n");
                        printf("\n \t\t\t\tContinue? y/n: ");
                        scanf(" %c", &cont);
                    } else{
                        printf("\t\t\tInvalid\n");
                    }
        } else if(scene4 == 3){
                inventory(&player);
        }
        else{
            printf("\t\t\tInvalid\n");
        }

    } while(cont == 'n');

    sleep(2);
    cont = 'n';
    do{
        int scene5;
        printf("\n\n \t\t\tThe sun has fallen, and what took its place is the crimson moon.\n");
        printf("\t\t\tYou saw a camp in the distance\n");
        printf("\t\t\t\t1. Rest at the camp | 2. Continue your journey | 3. Inventory: ");
        scanf("%d", &scene5);

        if(scene5 == 1){
            printf("\t\t\tYou rested at the camp...\n");
            sleep(2);
            printf("\t\t\tYou woke up to a sudden rumble\n");
            sleep(1);
            printf("\t\t\tA witch has raided your camp.\n");
            struct Enemy witch = create_witch();
            battle(&player, &witch);
            sleep(1);
            printf("\n \t\t\tYou quickly packed up and left\n");
            printf("\t\t\tContinue? y/n: ");
            scanf(" %c", &cont);
        } else if (scene5 == 2){
            printf("\t\t\tYou continued on your journey...\n");
            sleep(1);
            printf("\t\t\tYou encountered 2 witches on your path\n");

            struct Enemy witch = create_witch();
            struct Enemy witch2 = create_witch();
            battle(&player, &witch);
            battle(&player, &witch2);
            sleep(1);
            printf("\n \t\t\tLycantyopes smelled blood lingering in the air.\n");
            struct Enemy lycantrope = create_lycantrope();
            struct Enemy lycantrope2 = create_lycantrope();
            struct Enemy lycantrope3 = create_lycantrope();
            battle(&player, &lycantrope);
            battle(&player, &lycantrope2);
            battle(&player, &lycantrope3);
            sleep(1);
            printf("\n \t\t\tYou were exhausted after the encounter and realized that the sun is up.\n");
            printf("\t\t\tContinue? y/n: ");
            scanf(" %c", &cont);

        } else if(scene5 == 3){
            inventory(&player);

        } else {
            printf("\t\t\tInvalid\n");
        }
    } while(cont == 'n');
 
    cont = 'n';
    player.coins += 2000;
    do{
        int scene6;
        printf("\n\n \t\t\tOn you travels you encountered a merchant.\n");
        printf("\t\t\t\t1. Talk to the merchant | 2. Continue on your journey | 3. Inventory:  ");
        scanf("%d", &scene6);

    if(scene6 == 1){
        printf("\t\t\tYou approached the merchant...\n");
        sleep(1);

        merchant(&player);

    } else if(scene6 == 2){
        printf("\n \t\t\t You continued on your Journey...\n");
        printf("\t\t\t Continue? y/n: ");
        scanf(" %c", &cont);
    } else if (scene6 == 3){
        inventory(&player);

    } else {
        printf("\t\t\tInvalid\n");
    }

    }while(cont == 'n');





return 0;

}

void inventory(struct Player *player){
    int choice;
    do {
    printf("\n\n \t\t\t\tINVENTORY:\n");
    printf("\t\t\t\t1.Heal \t\t\t | Player Race: %s\n", player->race);
    printf("\t\t\t\t2.Exit Inventory \t | Player Hp: %d\n", player->total_hp);
    printf("\t\t\t\t3.Quit \t\t\t | Player Dps: %d\n", player->total_dmg);
    printf("\t\t\t\t\t\t\t | Totem: %s\n ", player->totem);
    printf("\t\t\t\t\t\t\t | Level: %d\n", player->level);
    printf("\t\t\t\t\t\t\t | Coins: %lf\n", player->coins);

     for (int i = 0; i < player->inventory_count; i++) {
            printf("\n \t\t\t\t%d. %s\n", i + 4, player->inventory[i].name);
        }

        printf("\t\t\t\tEnter choice (1-3 for existing options, 4+ for items, 0 to exit): ");
        scanf("%d", &choice);

        if (choice >= 4 && choice < 4 + player->inventory_count) {
            display_item_details(player->inventory[choice - 4]);
        } else if (choice == 1) {
              printf("\n \t\t\t\tYou have %d health bottles.\n", player->hp_bottles);
            sleep(1);
            if(player->hp_bottles > 0){
                printf("\t\t\t\tYou healed 30 hp.\n");
                player->total_hp += 30;
                player->hp_bottles--;
            }
        } else if (choice == 2) {
            // Exit inventory
            break;
        } else if (choice == 3) {
            exit(0);
        } else if (choice != 0) {
            printf("\t\t\tInvalid Input.\n");
        }
    } while (choice != 0);
}

void lvlup(struct Player *player){
    if(player->sub_level >= 100){
        printf("\n \t\t\t\tYou have leveled up\n");
        player->level ++;
        sleep(1);
        printf("\t\t\t\tAll stats are increased by 2.\n");
        player->total_dmg += 2;
        player->total_hp += 2;
        printf("\t\t\t\tYou are now level %d\n", player->level);
        player->sub_level = 0;

    }
}

void battle(struct Player *player, struct Enemy *enemy) {
    printf("\n\n\n \t\t\tYou've encountered a %s!\n", enemy->name);

    // Check for race advantage
     int bonus_damage = 0;
    int reduced_enemy_damage = 0;
    if (strcmp(player->race.name, enemy->weakness) == 0) {
        bonus_damage = 5;
        reduced_enemy_damage = 6;
        printf("\t\t\tYour race is strong against %s! You'll deal +5 damage and receive -6 damage.\n", enemy->name);
    } else if(strcmp(enemy->name, player->race.weakness) == 0){
        bonus_damage = -5;
        reduced_enemy_damage = -6;
        printf("\t\t\tYour race is weak against %s! You'll deal -5 damage and receive +6 damage.\n", enemy->name);
    } else {
        printf("\t\t\tYour race has no special interaction with the enemy\n");
    }



    while (1) {
        printf("\n \t\tYour HP: %d  \t\t\t\t | %s's HP: %d\n", player->total_hp, enemy->name, enemy->hp);
        printf("\t\tWhat will you do?\n");
        printf("\t\t1. Attack\n");
        printf("\t\t2. Run away\n");
        printf("\t\t3. Heal\n");

        int choice;
        printf("\t");
        scanf("%d", &choice);

        if (choice == 1) {
            // Player attacks
            int damage_dealt = player->total_dmg + bonus_damage;
            damage_dealt = (damage_dealt > 0) ? damage_dealt : 1;
            enemy->hp -= damage_dealt;
            printf("\t\t\tYou dealt %d damage to the %s!\n", damage_dealt, enemy->name);
            sleep(1);

            if (enemy->hp <= 0) {
                int n = 20;
                int coins = rand() % (n + 1);

                printf("\t\t\tYou defeated the %s!\n", enemy->name);
                sleep(1);

                srand(time(NULL));
                player->coins += coins;
                printf("\t\t\t%s dropped %d coins\n", enemy->name, coins);
                sleep(1);

                if (rand() % 5 == 0) {
                    struct Item dropped_item = generate_random_item(); // You'll need to implement this function
                    printf("\t\t\t%s dropped an item: %s\n", enemy->name, dropped_item.name);
                    add_item_to_inventory(player, dropped_item);
                }

                if(rand() % 3 == 0){
                    printf("\t\t\t%s dropped a health potion.\n", enemy->name);
                    player->hp_bottles++;
                    sleep(1);
                }

                if(player->contract == 1){
                    printf("\t\t\tYou received %d experience points", enemy->xp);
                    player->sub_level += enemy->xp;
                    sleep(1);
                    lvlup(player);
                    return;
            } else {
                return;
            }
            }
        }


            // Enemy attacks
            int enemy_damage = enemy->dmg - reduced_enemy_damage;
            enemy_damage = (enemy_damage > 0) ? enemy_damage : 1; // Ensure minimum 1 damage
            player->total_hp -= enemy_damage;
            printf("\t\t\tThe %s dealt %d damage to you!\n", enemy->name, enemy_damage);
            sleep(1);

            if (player->total_hp <= 0) {
                printf("\t\t\tYou were defeated by the %s...\n", enemy->name);
                exit(0);
            }
        else if (choice == 2) {
            // Attempt to run away
            srand(time(NULL));

            printf("\t\t\tYou tried to run away.\n");
            sleep(1);
            if (rand() % 2 == 0) {
                printf("\t\t\tYou successfully ran away!\n");
                return;
            } else {
                printf("\t\t\tYou failed to run away!\n");
                sleep(1);
                // Enemy attacks
                int enemy_damage = enemy->dmg - reduced_enemy_damage;
                enemy_damage = (enemy_damage > 0) ? enemy_damage : 1; // Ensure minimum 1 damage
                player->total_hp -= enemy_damage;
                printf("\t\t\tThe %s dealt %d damage to you!\n", enemy->name, enemy_damage);

                if (player->total_hp <= 0) {
                    printf("\t\t\tYou were defeated by the %s...\n", enemy->name);
                    exit(0);
            }
            }
        }
        else if(choice == 3){
                //attempt to heal
            srand(time(NULL));
                printf("\t\t\tThere is a 50% cchance for a heal to fail.\n");
                sleep(1);
            if(rand() %2 == 0){
                player->total_hp += 20;
                printf("\t\t\t20 hp has been recovered\n");
                sleep(1);

                int enemy_damage = enemy->dmg - reduced_enemy_damage;
                enemy_damage = (enemy_damage > 0) ? enemy_damage : 1; // Ensure minimum 1 damage
                player->total_hp -= enemy_damage;
                printf("\t\t\tThe %s dealt %d damage to you!\n", enemy->name, enemy_damage);

                if (player->total_hp <= 0) {
                    printf("\t\t\tYou were defeated by the %s...\n", enemy->name);
                    exit(0);
                    }
            } else {
                printf("\t\t\tFailed to heal\n");
                sleep(1);

                 int enemy_damage = enemy->dmg - reduced_enemy_damage;
                enemy_damage = (enemy_damage > 0) ? enemy_damage : 1; // Ensure minimum 1 damage
                player->total_hp -= enemy_damage;
                printf("\t\t\tThe %s dealt %d damage to you!\n", enemy->name, enemy_damage);

                if (player->total_hp <= 0) {
                    printf("\t\t\tYou were defeated by the %s...\n", enemy->name);
                    exit(0);
                    }
                }
        }
        else if(choice != 1 || choice != 2 || choice != 3){
            printf("\t\t\tInvalid choice. Please try again.\n");
        }
    }
}

void merchant(struct Player *player) {
    int choice;
    do {
        sleep(1);
        printf("\n \t\t\tWelcome to the Merchant!\n");
        printf("\t\t\t1. Buy\n");
        printf("\t\t\t2. Sell\n");
        printf("\t\t\t3. Exit\n");
        printf("\t\t\tYour coins: %lf\n", player->coins);
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                buy_items(player); //WIP
                break;
            case 2:
                sell_items(player);
                break;
            case 3:
                printf("\t\t\tThank you for your business!\n");
                break;
            default:
                printf("\t\t\tInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
}
void buy_items(struct Player *player) {
    struct Item available_items[] = {
        {"Potion", "Restores 50 HP", 30},
        {"Elixir of Strength", "Increases damage by 5 for the next battle", 50},
        {"Lucky Charm", "Increases chance of item drops", 75},
        {"Mysterious Amulet", "It glows faintly", 100}
    };
    int num_items = sizeof(available_items) / sizeof(available_items[0]);

    int choice;
    do {
        printf("\n\t\t\tItems available for purchase:\n");
        for (int i = 0; i < num_items; i++) {
            printf("\t\t\t%d. %s - %s (Cost: %d coins)\n", i + 1, available_items[i].name, available_items[i].description, available_items[i].value);
        }
        printf("\t\t\t%d. Exit\n", num_items + 1);
        printf("\t\t\tEnter the number of the item you want to buy: ");
        scanf("%d", &choice);

        if(choice == 1){
         if(player->coins > 30){
            player->coins -= 30;
            printf("\t\t\t  You bought a health potion.\n");
            player->hp_bottles ++;
            player->inventory_count ++;
            printf("\t\t\t Health Potions: %d", player->hp_bottles);
        } else {
            printf("\t\t\t You dont have enough coins.\n");
        }
        }

        if (choice > 1 && choice <= num_items) {
            struct Item selected_item = available_items[choice - 1];
            if (player->coins >= selected_item.value) {
                if (player->inventory_count < MAX_INVENTORY) {
                    player->coins -= selected_item.value;
                    add_item_to_inventory(player, selected_item);
                    printf("\t\t\tYou bought %s for %d coins.\n", selected_item.name, selected_item.value);
                } else {
                    printf("\t\t\tYour inventory is full. You cannot buy %s.\n", selected_item.name);
                }
            } else {
                printf("\t\t\tYou don't have enough coins to buy %s.\n", selected_item.name);
            }
        } else if (choice != num_items + 1) {
            printf("\t\t\tInvalid choice. Please try again.\n");
        }
    } while (choice != num_items + 1);
}



void sell_items(struct Player *player) {
    if (player->inventory_count == 0) {
        printf("\t\t\tYou have no items to sell.\n");
        return;
    }

    printf("\t\t\tYour items:\n");
    for (int i = 0; i < player->inventory_count; i++) {
        printf("\t\t\t%d. %s (Value: %d coins)\n", i + 1, player->inventory[i].name, player->inventory[i].value);
    }

    int choice;
    printf("\t\t\tEnter the number of the item you want to sell (0 to cancel): ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= player->inventory_count) {
        int index = choice - 1;
        player->coins += player->inventory[index].value;
        printf("\t\t\tSold %s for %d coins.\n", player->inventory[index].name, player->inventory[index].value);
        remove_item_from_inventory(player, index);
    } else if (choice != 0) {
        printf("\t\t\tInvalid choice.\n");
    }
}

void add_item_to_inventory(struct Player *player, struct Item item) {
    if (player->inventory_count < MAX_INVENTORY) {
        player->inventory[player->inventory_count] = item;
        player->inventory_count++;
        printf("\t\t\tAdded %s to your inventory.\n", item.name);
    } else {
        printf("\t\t\tInventory is full. Cannot add %s.\n", item.name);
    }
}

void remove_item_from_inventory(struct Player *player, int index) {
    if (index >= 0 && index < player->inventory_count) {
        for (int i = index; i < player->inventory_count - 1; i++) {
            player->inventory[i] = player->inventory[i + 1];
        }
        player->inventory_count--;
    }
}

void display_item_details(struct Item item) {
    printf("\t\t\tItem: %s\n", item.name);
    printf("\t\t\tDescription: %s\n", item.description);
    printf("\t\t\tValue: %d coins\n", item.value);
}


