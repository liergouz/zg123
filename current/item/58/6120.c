
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit WAIST;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return 1; }	//�ڼ���
// ��������������
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 6; }
//��װ����
string get_suit_name() { return "������װ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(8713);
        set_picid_2(8713);

        set_level(120);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 164);
        set("cp+", 0);
        set("pp+", 226);
        set("sp+", 0);
        set("hp+", 174);
        set("mp+", 120);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "������װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

