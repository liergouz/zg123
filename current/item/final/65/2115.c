
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2276; }

// ���������촦��
void create()
{
        set_name("ħ����");
        set_picid_1(6542);
        set_picid_2(6542);

        set_level(115);
        set_value(11500);
        set_max_lasting(27899);
        set("ap", 0);
        set("dp", 216);
        set("cp", 0);
        set("pp", 77);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ħ����";
}
