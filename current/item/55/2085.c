
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit HEAD;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return 1; }	//�ڼ���
// ��������������
int get_family() { return 2; }
//��װ����
string get_suit_name() { return "����"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("����ñ��");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(85);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 147);
        set("cp+", 0);
        set("pp+", 98);
        set("sp+", 0);
        set("hp+", 105);
        set("mp+", 100);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ñ��";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "������װ����֮һ,�ഫ����ȫ�׾ͻ�ӵ�����ص�����";
}

