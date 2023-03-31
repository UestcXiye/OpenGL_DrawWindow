/***
* ����  ���ƴ��� (MAKE������ʱ��ɾ��ALL_BUILD��Ҳ���Խ�Task-window��ΪĬ����������)
* ����:
* 1-��ʼ��:   GLFW���ڣ�GLAD��
* 2-��Ⱦ:     ��ջ��壬������������鴥���¼����ͷ���Դ
*/

#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// ��Ļ����
int screen_width = 1280;
int screen_height = 720;

int main()
{
	glfwInit();// ��ʼ��GLFW
	// OpenGL�汾Ϊ3.3�����ΰ汾�ž���Ϊ3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// ʹ�ú���ģʽ(������������)
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);// ���ʹ�õ���Mac OS Xϵͳ�����������
	glfwWindowHint(GLFW_RESIZABLE, false);// ���ɸı䴰�ڴ�С
	// ��������(���ߡ���������)
	auto window = glfwCreateWindow(screen_width, screen_height, "window", nullptr, nullptr);
	if (window == nullptr)
	{
		// ������ڴ���ʧ�ܣ����Failed to Create OpenGL Context
		std::cout << "Failed to Create OpenGL Context" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);// �����ڵ�����������Ϊ��ǰ�̵߳���������
	// ��ʼ��GLAD������OpenGL����ָ���ַ�ĺ���
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	// ָ����ǰ�ӿڳߴ�(ǰ��������Ϊ���½�λ�ã���������������Ⱦ���ڿ���)
	glViewport(0, 0, screen_width, screen_height);
	// ��Ⱦѭ��
	while (!glfwWindowShouldClose(window))
	{
		// �����ɫ����
		glClearColor(0.0f, 0.34f, 0.57f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// �������岢�Ҽ���Ƿ��д����¼�(����������롢����ƶ��ȣ�
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// �������е���Դ����ȷ�˳�����
	glfwTerminate();

	return 0;
}
