
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
int get_family() { return 3; }
//��װ����
string get_suit_name() { return "��ʨ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("��ʨ����");
        set_picid_1(8708);
        set_picid_2(8708);

        set_level(65);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 105);
        set("cp+", 0);
        set("pp+", 85);
        set("sp+", 0);
        set("hp+", 178);
        set("mp+", 0);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ʨ����";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "��ʨ��װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

