
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit BOOTS;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return 1; }	//�ڼ���
// ��������������
int get_family() { return 7; }
//��װ����
string get_suit_name() { return "��¹"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("��¹֮ѥ");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(75);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 42);
        set("cp+", 0);
        set("pp+", 45);
        set("sp+", 70);
        set("hp+", 65);
        set("mp+", 117);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��¹֮ѥ";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "��¹��װ����֮һ,�ഫ����ȫ�׾ͻ�ӵ�����ص�����";
}

