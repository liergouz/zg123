
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit BOOTS;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return 1; }	//�ڼ���
// ��������������
int get_family() { return 6; }
//��װ����
string get_suit_name() { return "��ӥ"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("��ӥ��ѥ");
        set_picid_1(8813);
        set_picid_2(8813);

        set_level(75);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 55);
        set("cp+", 0);
        set("pp+", 49);
        set("sp+", 69);
        set("hp+", 65);
        set("mp+", 90);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ӥ��ѥ";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "��ӥ��װ����֮һ,�ഫ����ȫ�׾ͻ�ӵ�����ص�����";
}

