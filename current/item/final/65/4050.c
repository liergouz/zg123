
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1275; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6603);
        set_picid_2(6603);

        set_level(50);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 75);
        set("cp", 0);
        set("pp", 39);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
