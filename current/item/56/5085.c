
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
int get_family() { return 5; }
//��װ����
string get_suit_name() { return "ս��"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("ս��Ƥ��");
        set_picid_1(6142);
        set_picid_2(6142);

        set_level(85);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 148);
        set("cp+", 0);
        set("pp+", 282);
        set("sp+", 0);
        set("hp+", 135);
        set("mp+", 192);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ս��Ƥ��";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "ս����װ����֮һ,�ഫ����ȫ�׾ͻ�ӵ�����ص�����";
}

