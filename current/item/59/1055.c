
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
int get_family() { return 1; }
//��װ����
string get_suit_name() { return "����"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("����֮ѥ");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(55);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 55);
        set("cp+", 0);
        set("pp+", 0);
        set("sp+", 20);
        set("hp+", 80);
        set("mp+", 0);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����֮ѥ";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "������װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

