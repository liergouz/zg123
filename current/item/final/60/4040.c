
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1244; }

// ���������촦��
void create()
{
        set_name("������װ");
        set_picid_1(6003);
        set_picid_2(6003);

        set_level(40);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 110);
        set("cp", 0);
        set("pp", 75);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������װ";
}
