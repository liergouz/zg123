
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��Ǭ��");
        set_picid_1(6582);
        set_picid_2(6582);

        set_level(120);
        set_value(56500);
        set_max_lasting(10899);
        set("dp", 79);
        set("pp", 157);

        setup();

        set_gender(1);
        set_head_code(48);
}

// ��������ȡ����
string get_desc()
{
        return "��Ǭ��";
}
