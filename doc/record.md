## 参考

https://github.com/zauonlok/renderer.git

## 资源管理

为了灵活，使用指针，new创建对象，delete释放对象


## 模块划分

graphic - 图形api相关：framebuffer，光栅化流水线

gui - gui

shader - 着色器

platform - 平台相关：输入输出管理（鼠标键盘），窗口绘制，framebuffer绘制，GUI

texture - 提供纹理对象（2D和立方体两种）

image - 提供图片对象

camera - 提供各类相机，同时可以用鼠标操作

mesh - 从文件中读取结点组，用于绘制

maths - 数学库，提供数学类型和一些转换



