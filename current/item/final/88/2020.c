
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1218; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(20);
        set_value(2000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 14);
        set("cp", 0);
        set("pp", 0);
        set("sp", 14);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
