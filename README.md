# 🐱 Flow2D - Cute OpenGL Cat

This project is a simple and charming OpenGL 2D drawing of a cat using the **GLUT** library.  
It’s meant to demonstrate basic 2D graphics programming in OpenGL, with a mix of geometric shapes and transformations.  
Let’s walk through how the code works! 🧶

---

## 💡 About the Code

### 🐾 Structure

The project is structured around a main display function that calls a custom `drawCat()` function.  
The scene includes:

- A **cat head** made of a black circle.
- **Ears** made with black triangles and inner brown triangles.
- **Eyes** using concentric circles for the iris, pupil, and highlights.
- A **nose and mouth** using rectangles and lines.
- The text **“OW”** drawn near the cat’s face.

These elements are carefully positioned using **OpenGL’s primitive shapes** (like `GL_POLYGON`, `GL_TRIANGLES`, `GL_LINES`, etc.).

---

### 🧱 Techniques Used

- **Primitive shapes**: To create the cat and facial features.
- **Transformation**: (if implemented) Using translation, rotation, or scaling for animation or positioning.
- **Coloring**: `glColor3f()` is used to apply solid colors to each part.
- **Buffer clearing**: `glClear()` and `glFlush()` manage the render flow.
- **Coordinate system**: Positions are set in a normalized space with `glOrtho()`.

---

## 🚀 Functions Breakdown

### `void display()`

- Clears the screen.
- Calls the `drawCat()` function to render the scene.
- Flushes the drawing buffer to the screen.

### `void drawCat()`

- Draws each part of the cat step-by-step.
- Groups ears, eyes, nose, mouth, and text as separate shape blocks.
- Makes use of loops or symmetry (if needed) to duplicate features like eyes.

You can customize this function to add animations, scale the cat, or even make it follow the mouse!

---

## 🎯 Learning Goals

This project is perfect if you’re learning:

- How to use **OpenGL in 2D**.
- How to break down a visual object into geometric parts.
- How to build reusable and modular drawing code.
- How to set up a simple OpenGL project with **GLUT**.

---

## 🛠️ To Do / Ideas

- Add simple animation (like blinking or head tilt).
- Let the user change the cat’s color!
- Add background or environment (moon, stars, etc.)

---

> 🐾 A simple, sweet intro to 2D OpenGL graphics — and a very good cat.
