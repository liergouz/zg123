
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
int get_family() { return 7; }
//��װ����
string get_suit_name() { return "Ů����װ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("�۾�");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(120);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 156);
        set("cp+", 0);
        set("pp+", 194);
        set("sp+", 0);
        set("hp+", 88);
        set("mp+", 200);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�۾�";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "Ů����װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

