
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit HEAD;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return 1; }	//�ڼ���
// ��������������
int get_family() { return 6; }
//��װ����
string get_suit_name() { return "ѩ��"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("ѩ����ñ");
        set_picid_1(6600);
        set_picid_2(6600);

        set_level(55);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 66);
        set("cp+", 0);
        set("pp+", 100);
        set("sp+", 0);
        set("hp+", 30);
        set("mp+", 80);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ѩ����ñ";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "ѩ����װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

