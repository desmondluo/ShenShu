#ifndef QT_CEF_POC_CEF_H_
#define QT_CEF_POC_CEF_H_

#include "include/cef_app.h"
/**
 * @brief CEF����
 */
class Cef {

public:
	/**
	 * @brief ���캯��
	 * @param argc ��������
	 * @param argv ����
	 */
	Cef(int argc, char *argv[]);
	/**
	 * @brief ��������
	 */
	~Cef();
	/**
	 * @brief �Ƿ��ʼ��ʧ��
	 * @param ��ʼ��ʧ�ܲ���
	 */
	int EarlyExitCode();
	/**
	 * @brief ��Ϣѭ������
	 */
	void Tick();
 private:
	//! �������ʧ�ܵĻ��ģ� ʧ����
	int early_exit_code_;
	//! CEF����������
	cef_main_args_t MainArgs(int argc, char *argv[]);
};

#endif // QT_CEF_POC_CEF_H_
