
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 1248; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6015);
        set_picid_2(6015);

        set_level(40);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 70);
        set("cp", 0);
        set("pp", 110);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
