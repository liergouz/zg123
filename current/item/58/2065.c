
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
int get_family() { return 2; }
//��װ����
string get_suit_name() { return "�ͻ�"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("�ͻ�����");
        set_picid_1(8712);
        set_picid_2(8712);

        set_level(65);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 108);
        set("cp+", 0);
        set("pp+", 98);
        set("sp+", 0);
        set("hp+", 70);
        set("mp+", 80);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ͻ�����";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "�ͻ���װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

