
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2309; }

// ���������촦��
void create()
{
        set_name("���Ƕ���");
        set_picid_1(6182);
        set_picid_2(6182);

        set_level(119);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 290);
        set("cp", 0);
        set("pp", 192);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "���Ƕ���";
}
