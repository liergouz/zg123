
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 1290; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6025);
        set_picid_2(6025);

        set_level(60);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 110);
        set("cp", 0);
        set("pp", 161);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
