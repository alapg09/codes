import random  # For generating random numbers
import math  # For mathematical functions
import pygame  # Main library for game development
from pygame import mixer  # For sound effects
import os  # For file operations

# initializing pygame
pygame.init()  # Start up all pygame modules

# creating the screen
screen = pygame.display.set_mode((800, 600))  # Set up the game window

# bg sound
mixer.music.load('background.wav')  # Load background music
mixer.music.play(-1)  # Play the music indefinitelny

# title and icon
pygame.display.set_caption("Space Invaders")  # Set the title of the window
icon = pygame.image.load('icon.png')  # Load the game icon
pygame.display.set_icon(icon)  # Set the window icon

# fonts
font = pygame.font.Font('font.ttf', 32)  # Font for score display
over_font = pygame.font.Font('font.ttf', 64)  # Font for game over message
restart_font = pygame.font.Font('font.ttf', 32)  # Font for restart instructions

# player
player_sprite = pygame.image.load('sprite.png')  # Load player sprite
playerX = 370  # Initial horizontal position of the player
playerY = 480  # Initial vertical position of the player
playerX_change = 0  # Change in horizontal position for movement

# multiple enemies
enemy_sprite = []  # List to store enemy sprites
enemyX = []  # List to store enemy horizontal positions
enemyY = []  # List to store enemy vertical positions
enemyX_change = []  # List to store enemy horizontal movement
enemyY_change = []  # List to store enemy vertical movement
num_of_enemies = 6  # Number of enemies in the game

def initialize_enemies():
    """Initialize the enemies with random positions and movement."""
    for i in range(num_of_enemies):
        enemy_sprite.append(pygame.image.load('enemy.png'))  # Load enemy sprite
        enemyX.append(random.randint(0, 735))  # Random horizontal position
        enemyY.append(random.randint(50, 150))  # Random vertical position
        enemyX_change.append(0.3)  # Set horizontal movement speed
        enemyY_change.append(20)  # Set vertical movement speed

initialize_enemies()  # Call the function to initialize enemies

# bomb variables
bomb_sprite = pygame.image.load('bomb.png')  # Load bomb sprite
bombX = []  # List to store bomb horizontal positions
bombY = []  # List to store bomb vertical positions
bombY_change = 0.2  # Speed of bomb falling
bomb_state = []  # State of each bomb (ready or dropping)
bomb_drop_interval = 100  # Interval for bomb dropping
bomb_timer = [0] * num_of_enemies  # Timer for each enemy's bomb dropping

# Initialize bomb positions and states
for i in range(num_of_enemies):
    bombX.append(0)  # Initial horizontal position of bombs
    bombY.append(0)  # Initial vertical position of bombs
    bomb_state.append("ready")  # Set initial state of bombs to ready

# bullet
bullet_sprite = pygame.image.load('bullet.png')  # Load bullet sprite
bulletX = 0  # Initial horizontal position of the bullet
bulletY = 480  # Initial vertical position of the bullet
bulletX_change = 0  # Change in horizontal position for bullet movement
bulletY_change = 1  # Change in vertical position for bullet movement
bullet_state = "ready"  # State of the bullet (ready or fired)

# Score and High Score
score_value = 0  # Current score
high_score = 0  # To keep track of the highest score

# File for saving high score
high_score_file = "highscore.txt"  # File to save the high score

# Load high score from file
def load_high_score():
    """Load the high score from a file."""
    global high_score
    if os.path.exists(high_score_file):  # Check if the high score file exists
        with open(high_score_file, "r") as file:  # Open the file in read mode
            high_score = int(file.read())  # Read the score and convert it to an integer
    else:
        high_score = 0  # If the file does not exist, set high score to 0

# Save high score to file
def save_high_score():
    """Save the high score to a file."""
    with open(high_score_file, "w") as file:  # Open the file in write mode
        file.write(str(high_score))  # Write the high score to the file

# Player lives
lives = 3  # Number of player lives

# Game over text and High Score display
def game_over_text():
    """Display game over text and high score."""
    global high_score
    if score_value > high_score:  # Check if the current score is higher than high score
        high_score = score_value  # Update high score
        save_high_score()  # Save new high score when game over

    over_text = over_font.render("GAME OVER", True, (0, 0, 0))  # Render game over text
    screen.blit(over_text, (200, 150))  # Display game over text on screen

    current_score_text = font.render(f"Score: {score_value}", True, (0, 0, 0))  # Render current score
    screen.blit(current_score_text, (300, 250))  # Display current score on screen

    high_score_text = font.render(f"High Score: {high_score}", True, (0, 0, 0))  # Render high score
    screen.blit(high_score_text, (300, 300))  # Display high score on screen

    restart_text = restart_font.render("Press R to Restart", True, (0, 0, 0))  # Render restart instruction
    screen.blit(restart_text, (250, 400))  # Display restart instruction on screen

# Reset game variables to restart the game
def restart_game():
    """Reset game variables to start a new game."""
    global score_value, lives, playerX, playerY, bulletY, bullet_state, enemyX, enemyY, enemyX_change, enemyY_change, bomb_timer, bomb_state, game_over

    score_value = 0  # Reset score
    lives = 3  # Reset lives
    playerX = 370  # Reset player position
    playerY = 480  # Reset player position
    bulletY = 480  # Reset bullet position
    bullet_state = "ready"  # Reset bullet state
    game_over = False  # Set game_over to False to continue the game
    
    enemyX.clear()  # Clear enemy X positions
    enemyY.clear()  # Clear enemy Y positions
    enemyX_change.clear()  # Clear enemy X movement
    enemyY_change.clear()  # Clear enemy Y movement
    bomb_timer = [0] * num_of_enemies  # Reset bomb timers
    bomb_state = ["ready"] * num_of_enemies  # Reset bomb states
    
    initialize_enemies()  # Reinitialize enemies

# Score and lives display
def show_score(x, y):
    """Display the current score on the screen."""
    score = font.render(f"Score: {score_value}", True, (0, 0, 0))  # Render the score
    screen.blit(score, (x, y))  # Display the score on the screen

def show_lives(x, y):
    """Display the current lives on the screen."""
    lives_text = font.render(f"Lives: {lives}", True, (0, 0, 0))  # Render the lives
    screen.blit(lives_text, (x, y))  # Display the lives on the screen

# Player movement
def player(x, y):
    """Render the player sprite on the screen."""
    screen.blit(player_sprite, (x, y))  # Display the player sprite at (x, y)

# Enemy rendering
def enemy(x, y, i):
    """Render the enemy sprite on the screen."""
    screen.blit(enemy_sprite[i], (x, y))  # Display the enemy sprite at (x, y)

# Fire bullet
def fire_bullet(x, y):
    """Render the bullet sprite on the screen when fired."""
    global bullet_state
    bullet_state = "fire"  # Change bullet state to fired
    screen.blit(bullet_sprite, (x + 16, y + 10))  # Display the bullet sprite

# Drop bomb
def drop_bomb(x, y):
    """Render the bomb sprite on the screen."""
    screen.blit(bomb_sprite, (x + 16, y + 10))  # Display the bomb sprite

# Collision detection for bullets
def isCollision(entityX, entityY, bulletX, bulletY):
    """Check for collision between an entity and a bullet."""
    distance = math.sqrt((math.pow(entityX - bulletX, 2)) + (math.pow(entityY - bulletY, 2)))  # Calculate distance
    return distance < 27  # Return True if the distance is less than 27 (collision threshold)

# Collision detection for bombs hitting player
def isBombHitPlayer(bombX, bombY, playerX, playerY):
    """Check for collision between a bomb and the player."""
    distance = math.sqrt((math.pow(bombX - playerX, 2)) + (math.pow(bombY - playerY, 2)))  # Calculate distance
    return distance < 27  # Return True if the distance is less than 27 (collision threshold)

# Load high score at the start
load_high_score()  # Load the high score when the game starts

# Main menu
def main_menu():
    """Display the main menu and handle user input."""
    menu_running = True  # Flag to control the menu loop
    while menu_running:
        screen.fill((255, 255, 255))  # Set background color to black
        title_text = over_font.render("SPACE INVADERS", True, (0, 0, 0))  # Render title text
        start_text = font.render("Press Enter to Start", True, (0, 0, 0))  # Render start instruction
        exit_text = font.render("Press Escape to Exit", True, (0, 0, 0))  # Render exit instruction

        # Display text on the screen
        screen.blit(title_text, (150, 150))
        screen.blit(start_text, (200, 250))
        screen.blit(exit_text, (200, 300))

        pygame.display.update()  # Update the display

        for event in pygame.event.get():  # Check for events
            if event.type == pygame.QUIT:  # If window is closed
                menu_running = False  # Exit the menu loop

            if event.type == pygame.KEYDOWN:  # If a key is pressed
                if event.key == pygame.K_RETURN:  # If Enter key is pressed
                    menu_running = False  # Exit the menu loop
                if event.key == pygame.K_ESCAPE:  # If Escape key is pressed
                    pygame.quit()  # Quit pygame
                    exit()  # Exit the program

# Game loop
running = True  # Flag to control the main game loop
game_over = False  # Flag to control game over state

# Show main menu
main_menu()  # Display the main menu

while running:  # Main game loop
    screen.fill((255, 255, 255))  # Set background color

    for event in pygame.event.get():  # Check for events
        if event.type == pygame.QUIT:  # If window is closed
            running = False  # Exit the main loop

        if not game_over:  # If the game is not over
            if event.type == pygame.KEYDOWN:  # If a key is pressed
                if event.key == pygame.K_LEFT:  # If left arrow key is pressed
                    playerX_change = -0.5  # Move player left
                if event.key == pygame.K_RIGHT:  # If right arrow key is pressed
                    playerX_change = 0.5  # Move player right
                if event.key == pygame.K_SPACE:  # If spacebar is pressed
                    if bullet_state == "ready":  # If bullet is ready to fire
                        bullet_sound = mixer.Sound('laser.wav')  # Load bullet sound
                        bullet_sound.play()  # Play bullet sound
                        bulletX = playerX  # Set bullet's initial horizontal position
                        fire_bullet(bulletX, bulletY)  # Fire the bullet

            if event.type == pygame.KEYUP:  # If a key is released
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:  # If left or right arrow key is released
                    playerX_change = 0  # Stop player movement

        # Restart game on Game Over screen if 'R' is pressed
        if game_over and event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:  # If 'R' key is pressed
                restart_game()  # Restart the game

    if game_over:  # If the game is over
        game_over_text()  # Display game over text
        pygame.display.update()  # Update the display
        continue  # Skip to the next iteration of the loop

    # Player movement
    playerX += playerX_change  # Update player position
    if playerX <= 0:  # If player goes out of bounds on the left
        playerX = 0  # Reset to left boundary
    elif playerX >= 736:  # If player goes out of bounds on the right
        playerX = 736  # Reset to right boundary

    # Enemy movement and bomb dropping
    for i in range(num_of_enemies):
        if enemyY[i] > 440:  # If any enemy reaches the bottom of the screen
            for j in range(num_of_enemies):
                enemyY[j] = 2000  # Move all enemies off-screen
            game_over = True  # Set game over state to True

        enemyX[i] += enemyX_change[i]  # Update enemy position
        if enemyX[i] <= 0:  # If enemy hits left boundary
            enemyX_change[i] = 0.3  # Change direction to right
            enemyY[i] += enemyY_change[i]  # Move down
        elif enemyX[i] >= 736:  # If enemy hits right boundary
            enemyX_change[i] = -0.3  # Change direction to left
            enemyY[i] += enemyY_change[i]  # Move down

        bomb_timer[i] += 1  # Increment bomb timer
        if bomb_timer[i] >= bomb_drop_interval and bomb_state[i] == "ready":  # Check if it's time to drop a bomb
            bombX[i] = enemyX[i]  # Set bomb horizontal position to enemy's
            bombY[i] = enemyY[i]  # Set bomb vertical position to enemy's
            bomb_state[i] = "drop"  # Change bomb state to dropping
            bomb_timer[i] = 0  # Reset bomb timer

        if bomb_state[i] == "drop":  # If the bomb is dropping
            drop_bomb(bombX[i], bombY[i])  # Render the bomb
            bombY[i] += bombY_change  # Move the bomb down

        if isBombHitPlayer(bombX[i], bombY[i], playerX, playerY):  # Check if the bomb hits the player
            bomb_state[i] = "ready"  # Reset bomb state
            lives -= 1  # Decrease player lives
            if lives == 0:  # If player has no lives left
                for j in range(num_of_enemies):
                    enemyY[j] = 2000  # Move all enemies off-screen
                game_over = True  # Set game over state to True

        if bombY[i] > 600:  # If bomb goes off the screen
            bomb_state[i] = "ready"  # Reset bomb state

        collision = isCollision(enemyX[i], enemyY[i], bulletX, bulletY)  # Check for bullet collision with enemy
        if collision:  # If a collision occurs
            explosion_sound = mixer.Sound('explosion.wav')  # Load explosion sound
            explosion_sound.play()  # Play explosion sound
            bulletY = 480  # Reset bullet position
            bullet_state = "ready"  # Reset bullet state
            score_value += 1  # Increase score
            enemyX[i] = random.randint(0, 735)  # Reset enemy's horizontal position
            enemyY[i] = random.randint(50, 150)  # Reset enemy's vertical position

        enemy(enemyX[i], enemyY[i], i)  # Render the enemy

    # Bullet movement
    if bulletY <= 0:  # If bullet goes off the screen
        bulletY = 480  # Reset bullet position
        bullet_state = "ready"  # Reset bullet state
    if bullet_state == "fire":  # If bullet is fired
        fire_bullet(bulletX, bulletY)  # Render the bullet
        bulletY -= bulletY_change  # Move the bullet up

    # Player rendering and score/lives display
    player(playerX, playerY)  # Render the player
    show_score(10, 10)  # Display the score
    show_lives(650, 10)  # Display the lives

    pygame.display.update()  # Update the display