
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 1238; }

// ���������촦��
void create()
{
        set_name("��¶Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(30);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 10);
        set("cp", 0);
        set("pp", 0);
        set("sp", 15);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��¶Ь";
}
