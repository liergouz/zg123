
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
int get_family() { return 5; }
//��װ����
string get_suit_name() { return "��ʿ��װ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("��ɫ");
        set_picid_1(8662);
        set_picid_2(8662);

        set_level(120);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 0);
        set("cp+", 366);
        set("pp+", 232);
        set("sp+", 0);
        set("hp+", 100);
        set("mp+", 200);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ɫ";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "��ʿ��װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

