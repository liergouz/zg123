
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2182; }

// ���������촦��
void create()
{
        set_name("��Ӱ����װ");
        set_picid_1(6115);
        set_picid_2(6115);

        set_level(75);
        set_value(9000);
        set_max_lasting(22899);
        set("ap", 0);
        set("dp", 181);
        set("cp", 0);
        set("pp", 107);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ӱ����װ";
}
