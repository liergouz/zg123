
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
int get_family() { return 7; }
//��װ����
string get_suit_name() { return "Ů����װ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("è��");
        set_picid_1(8663);
        set_picid_2(8663);

        set_level(120);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 0);
        set("cp+", 340);
        set("pp+", 200);
        set("sp+", 0);
        set("hp+", 224);
        set("mp+", 270);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "è��";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "Ů����װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

