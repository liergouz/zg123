
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit ARMOR;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return 1; }	//�ڼ���
// ��������������
int get_family() { return 6; }
//��װ����
string get_suit_name() { return "��ӥ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("��ӥ����");
        set_picid_1(6125);
        set_picid_2(6125);

        set_level(75);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 126);
        set("cp+", 0);
        set("pp+", 235);
        set("sp+", 0);
        set("hp+", 85);
        set("mp+", 163);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ӥ����";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "��ӥ��װ����֮һ,�ഫ����ȫ�׾ͻ�ӵ�����ص�����";
}

