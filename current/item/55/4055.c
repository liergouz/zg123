
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
int get_family() { return 4; }
//��װ����
string get_suit_name() { return "�Ա�"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("�Ա�ͷ��");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(55);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 73);
        set("cp+", 0);
        set("pp+", 48);
        set("sp+", 23);
        set("hp+", 50);
        set("mp+", 0);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�Ա�ͷ��";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "�Ա���װ����֮һ,�ഫ����\nȫ�׾ͻ�ӵ�����ص�����";
}

