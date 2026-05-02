This project has been created as part of the 42 curriculum by tphuwian.
# FRACTOL

## 🖥️ Graphical Engine: MLX42

**MLX42** is a modern, cross-platform computer graphics library used within the 42 School curriculum[cite: 1]. Built as a wrapper over **GLFW** and **OpenGL**, it abstracts the low-level complexities of hardware-accelerated rendering, window management, and event handling. This allows developers to focus entirely on algorithmic logic and pixel-perfect rendering while maintaining high performance.

### ⚙️ Core Implementation & API Usage

This project meticulously utilizes MLX42's API to build a highly responsive and optimized fractal explorer. Below are the key functions and components integrated into the engine:

#### 1. Lifecycle & Window Management
*   `mlx_init()`: Initializes the graphical environment, underlying GLFW context, and opens the main application window with predefined dimensions.
*   `mlx_loop()`: Executes the infinite main loop, halting the program's linear progression to continuously listen for and process graphical events.
*   `mlx_close_window()` & `mlx_terminate()`: Ensures a clean program exit. These functions destroy the window context, terminate the background processes, and free all allocated memory to strictly prevent memory leaks.

#### 2. Advanced Memory & Rendering Management
*   `mlx_new_image()`: Allocates a dedicated memory block (canvas) for the graphical output.
*   `mlx_image_to_window()`: Pushes the fully rendered image buffer to the active display window.
*   **Direct Image Buffer Manipulation (`img->pixels`)**: 
    To achieve maximum rendering speed and extreme smoothness, this project bypasses the standard `mlx_put_pixel` function. Instead, it utilizes **Direct Memory Access (DMA)** to write RGBA byte values directly into the 1D image array using the optimized offset formula: `offset = (y * WIDTH + x) * 4`. This optimization significantly reduces function call overhead during deep fractal zooms.

#### 3. Event-Driven Programming (Hooks)
*   `mlx_loop_hook()`: Registers the core function (`ft_hook`) to be executed unconditionally every single frame. This provides a buttery-smooth user experience when holding down directional keys for panning.
*   `mlx_scroll_hook()`: An event listener dedicated to the mouse wheel (`ft_scroll_hook`). It intercepts scroll direction (`ydelta`) to dynamically calculate zoom multipliers and incrementally adjust iteration depth.
*   `mlx_is_key_down()`: A real-time state checker utilized within the loop hook to detect asynchronous key presses (`ESC`, `UP`, `DOWN`, `LEFT`, `RIGHT`) for immediate viewport translation.


---

## 🖥️ เอนจินกราฟิก: MLX42

**MLX42** เป็นไลบรารีกราฟิกคอมพิวเตอร์ข้ามแพลตฟอร์มที่ทันสมัย ซึ่งถูกนำมาใช้ในหลักสูตรของ 42 School ถูกสร้างขึ้นเป็นตัวครอบ (Wrapper) ทับ **GLFW** และ **OpenGL** เพื่อลดความซับซ้อนระดับล่าง (Low-level) ของการเรนเดอร์กราฟิกด้วยฮาร์ดแวร์ การจัดการหน้าต่าง และการจัดการเหตุการณ์ (Event handling) สิ่งนี้ช่วยให้นักพัฒนาสามารถโฟกัสไปที่ตรรกะของอัลกอริทึมและการเรนเดอร์พิกเซลที่สมบูรณ์แบบได้เต็มที่ โดยที่ยังคงประสิทธิภาพการทำงานขั้นสูงไว้

### ⚙️ การทำงานหลักและการใช้งาน API

โปรเจกต์นี้ใช้งาน API ของ MLX42 อย่างพิถีพิถันเพื่อสร้างโปรแกรมสำรวจ Fractal ที่ตอบสนองไวและได้รับการรีดประสิทธิภาพมาอย่างดี ด้านล่างนี้คือฟังก์ชันและองค์ประกอบหลักที่นำมาใช้:

#### 1. วงจรชีวิตโปรแกรมและการจัดการหน้าต่าง (Lifecycle & Window Management)
*   `mlx_init()`: เริ่มต้นสภาพแวดล้อมทางกราฟิกและบริบทของ GLFW ที่อยู่เบื้องหลัง รวมถึงเปิดหน้าต่างโปรแกรมหลักตามขนาดที่กำหนดไว้
*   `mlx_loop()`: รันลูปหลักแบบไม่รู้จบ (Infinite loop) ซึ่งจะหยุดการทำงานแบบเส้นตรงของโปรแกรม เพื่อคอยรับฟังและประมวลผลเหตุการณ์ทางกราฟิกอย่างต่อเนื่อง
*   `mlx_close_window()` & `mlx_terminate()`: รับประกันการปิดโปรแกรมอย่างสมบูรณ์ ฟังก์ชันเหล่านี้จะทำลายบริบทของหน้าต่าง ยุติโปรเซสพื้นหลัง และคืนพื้นที่หน่วยความจำทั้งหมดที่จองไว้เพื่อป้องกัน Memory Leak อย่างเคร่งครัด

#### 2. การจัดการหน่วยความจำและการเรนเดอร์ขั้นสูง (Advanced Memory & Rendering Management)
*   `mlx_new_image()`: จองบล็อกหน่วยความจำเฉพาะ (เปรียบเสมือนผ้าใบ) สำหรับแสดงผลกราฟิก
*   `mlx_image_to_window()`: ดันข้อมูลภาพที่เรนเดอร์เสร็จสมบูรณ์แล้วจาก Buffer ไปแสดงบนหน้าต่างที่กำลังใช้งานอยู่
*   **การจัดการ Image Buffer โดยตรง (`img->pixels`)**: 
    เพื่อให้ได้ความเร็วในการเรนเดอร์สูงสุดและความลื่นไหลขั้นสุด โปรเจกต์นี้ข้ามการใช้ฟังก์ชัน `mlx_put_pixel` แบบมาตรฐาน แต่หันไปใช้ **การเข้าถึงหน่วยความจำโดยตรง (Direct Memory Access)** เพื่อเขียนค่าไบต์ของ RGBA ลงในอาร์เรย์รูปภาพแบบ 1 มิติโดยตรง ผ่านสูตรคำนวณ Offset ที่ปรับแต่งมาแล้ว: `offset = (y * WIDTH + x) * 4` การรีดประสิทธิภาพจุดนี้ช่วยลด Overhead จากการเรียกใช้ฟังก์ชันได้อย่างมหาศาลในขณะที่ซูมเจาะลึกลงไปใน Fractal

#### 3. การเขียนโปรแกรมตอบสนองเหตุการณ์ (Event-Driven Programming & Hooks)
ส่วนนี้คือหัวใจสำคัญที่ทำให้โปรแกรมสามารถโต้ตอบกับผู้ใช้งานผ่านคีย์บอร์ดและเมาส์ได้อย่างลื่นไหล:
*   `mlx_loop_hook()`: เป็นการลงทะเบียนฟังก์ชันหลัก (เช่น `ft_hook`) ให้ทำงานวนซ้ำอย่างต่อเนื่องในทุกๆ เฟรม เทคนิคนี้ช่วยให้ผู้ใช้สามารถกดปุ่มลูกศรค้างไว้เพื่อเลื่อนภาพ (Panning) ได้อย่างสมูทที่สุด โดยไม่เกิดอาการกระตุกตามจังหวะดีเลย์ของคีย์บอร์ด
*   `mlx_scroll_hook()`: ฟังก์ชันดักจับเหตุการณ์ของลูกกลิ้งเมาส์โดยเฉพาะ (เช่น `ft_scroll_hook`) จะทำงานเมื่อมีการเลื่อนลูกกลิ้งเท่านั้น โดยจะรับทิศทางการเลื่อน (`ydelta`) มาคำนวณตัวคูณการซูม (Zoom multiplier) และปรับความละเอียด (Iterations) โดยอัตโนมัติ
*   `mlx_is_key_down()`: ฟังก์ชันเช็คสถานะปุ่มกดแบบเรียลไทม์ ซึ่งถูกเรียกใช้งานอยู่ภายใน Loop Hook เพื่อตรวจสอบการกดปุ่ม `ESC` (สำหรับการปิดโปรแกรมอย่างปลอดภัย) และปุ่มลูกศรทิศทาง (`UP`, `DOWN`, `LEFT`, `RIGHT`) สำหรับสั่งการเปลี่ยนพิกัดการมองเห็นบนหน้าจอ

---


## ----------------------------------------------
# Fract'ol 🌌
**Computer Graphics Fractals**

## 📖 1. Description
**Fract'ol** is a computer graphics project designed to explore the mathematical beauty of fractals, specifically the **Mandelbrot** and **Julia** sets. The primary goal of this project is to render these infinitely complex mathematical structures in a graphical window using the **MLX42** library. 

Beyond simply plotting mathematical formulas ($Z_{n+1} = Z_n^2 + C$), this project focuses heavily on **low-level memory optimization** and **event-driven programming** to ensure buttery-smooth real-time rendering, even at extreme zoom depths.

## 🛠️ 2. Instructions

### Compilation
The project comes with a `Makefile`. To compile the program, simply run:

1. make
2. Choose to run Julia or mandelbrot

<!--For mandelbrot no need to add anything.-->
Instead of Julia need to add more number in av[2], av[3]

Here's the step how to run

## Mandelbrot ##
./fractol mandelbrot

## Julia ##
./fractol real_num imaginary_num

## Controls

Scroll Wheel: Zoom in and out dynamically (automatically adjusts rendering iterations for visual clarity).

Arrow Keys (UP, DOWN, LEFT, RIGHT): Smooth proportional panning across the complex plane.

ESC Key / Window Cross: Cleanly exit the program and free all allocated memory.

## ⚙️ 3. Technical Choices & Feature List (Extra)
To achieve maximum performance and comply with strict code quality standards, several advanced techniques were implemented:

Direct Memory Access (Image Buffering): Instead of calling mlx_put_pixel for every single coordinate, the program calculates the 1D array offset ((y * WIDTH + x) * 4) and writes RGBA byte values directly into the image buffer (img->pixels). This drastically reduces function-call overhead.

Cardioid Checking Bypass: For the Mandelbrot set, a mathematical formula is used to check if a coordinate falls within the main cardioid or the period-2 bulb. If it does, the program skips the expensive while loop entirely, saving up to 50% of CPU resources.

Norm-Compliant Architecture: Rendering logic is strictly separated from pixel-writing functions to ensure all code complies with the 42 Norminette (maximum 25 lines per function).

## AI Usage Declaration

Artificial Intelligence (LLM) was utilized during the development of this project for the following specific tasks:

Algorithm Optimization: Used AI to understand and implement the mathematical formula for the "Cardioid Checking Bypass" to optimize Mandelbrot rendering speed.

Refactoring: Consulted AI for best practices on breaking down the render_pixels function to strictly comply with the 42 Norminette (25-line limit) while maintaining the Direct Memory Access logic.

Documentation: Used AI to help structure, proofread, and translate technical concepts (like MLX42 engine mechanics) into professional English for this README file.