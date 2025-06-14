# 🎲 Marble Guessing Game

A simple, interactive terminal game written in C++ where you compete against a computer in a battle of luck and deduction. Each player starts with marbles and takes turns guessing whether the opponent's hidden number is odd or even.

---

## 🧠 Game Concept

- You and the computer both start with **10 marbles**.
- Each round:
  1. One player secretly chooses a number of marbles from their stash.
  2. The opponent guesses whether the number is **odd** or **even**.
  3. If the guess is correct, the guessing player wins **all** of those marbles.
  4. If incorrect, no marbles are exchanged.
- The game continues until one player runs out of marbles.

---

## 📦 Features

- 🧮 Real-time marble tracking and display.
- 🧑‍🤝‍🧑 Player vs. Computer turns.
- 🎭 Input validation and in-game guidance.
- 🎉 Victory/defeat messages with playful formatting.
- 💬 Emoji-enhanced user interface for a fun terminal experience.

---

## ▶️ How to Play

1. Compile the code:
   g++ -o marble_game marble_game.cpp
2. Run the game:
   ./marble_game