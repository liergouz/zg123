
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit NECK;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return 1; }	//�ڼ���
// ��������������
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 3; }
//��װ����
string get_suit_name() { return "Ů����װ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("ľ��");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(120);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 220);
        set("dp+", 0);
        set("cp+", 0);
        set("pp+", 194);
        set("sp+", 0);
        set("hp+", 332);
        set("mp+", 0);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ľ��";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "Ů����װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

