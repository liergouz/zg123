
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
int get_family() { return 3; }
//��װ����
string get_suit_name() { return "��ʨ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("��ʨս��");
        set_picid_1(6042);
        set_picid_2(6042);

        set_level(55);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 203);
        set("cp+", 0);
        set("pp+", 106);
        set("sp+", 0);
        set("hp+", 165);
        set("mp+", 0);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ʨս��";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "��ʨ��װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

