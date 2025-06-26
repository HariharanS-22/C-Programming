# 🕹️ FLAMES Relationship Predictor in C 🎰

This is a terminal-based **FLAMES game** implemented in C.  
FLAMES stands for:

- **F** – Friends  
- **L** – Love  
- **A** – Affection  
- **M** – Marriage  
- **E** – Enemy  
- **S** – Sister

The game takes two names as input, processes them by removing common letters, and predicts the relationship between them based on the remaining count.


## 🧠 How It Works

1. Input two names (your name and your crush/friend).
2. Removes spaces and converts both names to lowercase.
3. Eliminates matching characters.
4. Adds the number of unmatched characters.
5. Uses this count to cyclically eliminate letters from the word **FLAMES**.
6. Outputs the final relationship result.


## 🛠️ How to Compile and Run

### 🔧 Requirements

- GCC or any C compiler

### 💻 Steps

1. Save the code in a file named `flames.c`
2. Open a terminal and compile the code:
   ```bash
   gcc flames.c -o flames
   ./flames

## ✨ Features
- Handles both lowercase and uppercase names

- Removes spaces automatically

- Works with any length names

- Recursive FLAMES logic implementation

- User can play repeatedly in a single run

 ## 📄 License
This project is licensed under the MIT License. See `LICENSE` for more details.
