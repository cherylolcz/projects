from flask import Blueprint, request, jsonify, render_template
from di.container import Container
from web.web_mapper import WebMapper

container = Container()

game_bp = Blueprint("game", __name__)


def get_response(response):
    return jsonify(response.__dict__)


@game_bp.route("/")
def index():
    return render_template("index.html")


@game_bp.route("/game/<uuid:game_id>", methods=["POST"])
def game_process(game_id):

    service = container.get_service()

    model = service.get_game(str(game_id))

    data = request.get_json()
    row = data["row"]
    col = data["col"]

    model = service.process_player_move(model, row, col)

    return get_response(WebMapper.to_web(model))


@game_bp.route("/game/new", methods=["POST"])
def new_game():

    service = container.get_service()
    model = service.create_game()

    return get_response(WebMapper.to_web(model))
