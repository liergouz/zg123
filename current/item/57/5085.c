
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
int get_family() { return 5; }
//��װ����
string get_suit_name() { return "ս��"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("ս������");
        set_picid_1(8662);
        set_picid_2(8662);

        set_level(85);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 25);
        set("cp+", 208);
        set("pp+", 141);
        set("sp+", 0);
        set("hp+", 95);
        set("mp+", 140);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ս������";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "ս����װ����֮һ,�ഫ����ȫ�׾ͻ�ӵ�����ص�����";
}

