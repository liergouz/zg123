
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
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 7; }
//��װ����
string get_suit_name() { return "��¹"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("��¹Ƥ��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(75);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 149);
        set("cp+", 0);
        set("pp+", 260);
        set("sp+", 0);
        set("hp+", 105);
        set("mp+", 147);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��¹Ƥ��";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "��¹��װ����֮һ,�ഫ����ȫ�׾ͻ�ӵ�����ص�����";
}

