
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
int get_family() { return 4; }
//��װ����
string get_suit_name() { return "�Ա�"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("�Ա�����");
        set_picid_1(8707);
        set_picid_2(8707);

        set_level(65);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 80);
        set("cp+", 0);
        set("pp+", 90);
        set("sp+", 30);
        set("hp+", 55);
        set("mp+", 0);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�Ա�����";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "�Ա���װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

