
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2020; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8809);
        set_picid_2(8809);

        set_level(70);
        set_value(5500);
        set_max_lasting(14899);
        set("ap", 0);
        set("dp", 30);
        set("cp", 0);
        set("pp", 0);
        set("sp", 35);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
